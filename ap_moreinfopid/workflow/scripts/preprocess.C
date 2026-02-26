#include <ROOT/RDataFrame.hxx>
#include <string>
#include <unordered_set>
#include <stdexcept>

double computeEnergy(Double_t px, Double_t py, Double_t pz, Double_t mass)
{
    double p2, E2, E;
    p2 = px * px + py * py + pz * pz;
    E2 = p2 + mass * mass;
    E = sqrt(E2);
    return E;
}

ROOT::RDF::RNode add_Xc_Selection(ROOT::RDF::RNode df, const char *mode, const char *pidgenfilename, bool isBKG = false)
{

    // Mode should be "Bs" or "Bd"
    if (strcmp(mode, "Bs") != 0 && strcmp(mode, "Bd") != 0)
    // if ((mode.substr(0,2) != "Bs") && (mode.substr(0,2) != "Bd"))
    {
        throw std::invalid_argument("Invalid mode. Use 'Bs' or 'Bd'.");
    }
    bool isBs = (strcmp(mode, "Bs") == 0);

    // Now checking whether we have a PID file anem of the value "noPIDcorr"
    bool applyPIDcorr = (strcmp(pidgenfilename, "noPIDcorr") != 0);


    auto compute_Xc_Selection = [isBs, isBKG](double Xc_MM,
                                          double p1_fromXc_PX, double p1_fromXc_PY, double p1_fromXc_PZ, double p1_fromXc_PE,
                                          double p2_fromXc_PX, double p2_fromXc_PY, double p2_fromXc_PZ, double p2_fromXc_PE,
                                          double p3_fromXc_PX, double p3_fromXc_PY, double p3_fromXc_PZ, double p3_fromXc_PE,
                                          double p1_fromXc_PIDK_pidgen_default, double p2_fromXc_PIDK_pidgen_default,
                                          double p3_fromXc_PIDK_pidgen_default, double p1_fromXc_PIDp_pidgen_default,
                                          double p2_fromXc_PIDp_pidgen_default, double p3_fromXc_PIDp_pidgen_default) -> int
    { // selection cuts are based on 4.2.1 in Alessandro's thesis (CERN-THESIS-2020-076)

        float cut_Xc_MM, cmptE_mass;
        if (isBs)
        {
            cut_Xc_MM = 1968;
            cmptE_mass = 139.57;
        }
        else
        {
            cut_Xc_MM = 1869;
            cmptE_mass = 493.68;
        }

	if (!isBKG) {
            if (fabs(Xc_MM - cut_Xc_MM) > 20) // to improve purity of selected D(s) signal
                return -1;
	}

        // D0->KK veto
        TLorentzVector K1(p1_fromXc_PX, p1_fromXc_PY, p1_fromXc_PZ, p1_fromXc_PE);
        TLorentzVector K2(p2_fromXc_PX, p2_fromXc_PY, p2_fromXc_PZ, p2_fromXc_PE); // pi2 for Bd
        TLorentzVector pi3(p3_fromXc_PX, p3_fromXc_PY, p3_fromXc_PZ, p3_fromXc_PE);

        if ((K1 + K2).M() > 1840) // to suppress misidentified kaon as pion or additional kaon or pion to form D(s)+
            return -1;

        double E = computeEnergy(p2_fromXc_PX, p2_fromXc_PY, p2_fromXc_PZ, cmptE_mass);
        TLorentzVector pi2(p2_fromXc_PX, p2_fromXc_PY, p2_fromXc_PZ, E);
        if (isBs)
        {
            if (fabs((K1 + pi2 + pi3).M() - 1869.65) <= 30 && p2_fromXc_PIDK_pidgen_default < 10) // Table 4.3 (misidentified D+)
                return -1;
        }
        else
        {
            if (fabs((K1 + pi2 + pi3).M() - 1968) <= 30 && p2_fromXc_PIDK_pidgen_default < 0) // Table 4.4 (misidentified Ds+)
                return -1;
        }

        E = computeEnergy(p2_fromXc_PX, p2_fromXc_PY, p2_fromXc_PZ, 938.27);
        TLorentzVector p2(p2_fromXc_PX, p2_fromXc_PY, p2_fromXc_PZ, E);
        if (isBs)
        {
            if (fabs((K1 + p2 + pi3).M() - 2286.46) < 30 && (p2_fromXc_PIDK_pidgen_default - p2_fromXc_PIDp_pidgen_default) < 5) // Table 4.3 (misidentified Lambdac+)
                return -1;
        }
        else
        {
            if (fabs((K1 + p2 + pi3).M() - 2286.46) < 30 && p2_fromXc_PIDp_pidgen_default < 0) // Table 4.4 (misidentified Lambdac+)
                return -1;
        }

        if (isBs)
        {
            if (fabs((K1 + K2).M() - 1020) <= 12) // Table 4.2 (phi resonance)
            {

                if (!(p1_fromXc_PIDK_pidgen_default > -2 && p2_fromXc_PIDK_pidgen_default > -2))
                {
                    return -1;
                }
            }
            else if (fabs((K1 + pi3).M() - 892) <= 50) // Table 4.2 (K*0 resonance)
            { // k star mass

                if (!(p1_fromXc_PIDK_pidgen_default > -2 && p2_fromXc_PIDK_pidgen_default > 5))
                {
                    return -1;
                }
            }
            else // Table 4.2 (non-resonance)
            {

                if (!(p1_fromXc_PIDK_pidgen_default > 5 && p2_fromXc_PIDK_pidgen_default > 5 && p3_fromXc_PIDK_pidgen_default < 10))
                {
                    return -1;
                }
            }
        } // isBs

        return 1;
    };

    std::string pidCorr = "";
    if (applyPIDcorr)
    {
        pidCorr = "_pidgen_default";
    }

    std::string colName = "Xc_Selection";
    if (isBKG) {colName = "Xc_Selection_BDTbkg";}

    auto ret = df.Define((colName).c_str(), compute_Xc_Selection,
                         {"Xc_MM",
                          "p1_fromXc_PX", "p1_fromXc_PY", "p1_fromXc_PZ", "p1_fromXc_PE",
                          "p2_fromXc_PX", "p2_fromXc_PY", "p2_fromXc_PZ", "p2_fromXc_PE",
                          "p3_fromXc_PX", "p3_fromXc_PY", "p3_fromXc_PZ", "p3_fromXc_PE",
                          ("p1_fromXc_PIDK" + pidCorr).c_str(), ("p2_fromXc_PIDK" + pidCorr).c_str(),
                          ("p3_fromXc_PIDK" + pidCorr).c_str(), ("p1_fromXc_PIDp" + pidCorr).c_str(),
                          ("p2_fromXc_PIDp" + pidCorr).c_str(), ("p3_fromXc_PIDp" + pidCorr).c_str()});

    return ret;
}

std::string get_preprocess_mode(const std::string &eventtype)
{
    static const std::unordered_set<std::string> bs_event_types = {
        "13563002", "13266069", "13863401", "13763200", "90000000"};

    static const std::unordered_set<std::string> bd_event_types = {
        "11266009"};

    if (bs_event_types.find(eventtype) != bs_event_types.end())
    {
        return "Bs";
    }
    else if (bd_event_types.find(eventtype) != bd_event_types.end())
    {
        return "Bd";
    }
    else
    {
        throw std::invalid_argument("Unknown eventtype " + eventtype + " for preprocessing.");
    }
}

/**
 * Preprocess the data by applying selections and saving to a new file.
 * @param config DIRAC config, i.e. lhcb for data and mc for simulation
 * @param datafilename Input data file name.
 * @param eventtype Event type string to determine the preprocessing mode i.e. whether we apply Bs or Bd selections.
 * @param pidgenfilename File containing the regenerated PID columns.
 * @param outputfilename Output file name.
 * @param filter Flag to indicate whether to apply filtering. Default is false.
 * @param isBKG Flag to indicate whether to select combinatorial background only (used for BDT training). Default is false.
 */
void preprocess(const char* config, const char *datafilename, const char *eventtype, 
    const char *pidgenfilename, const char *outputfilename, bool filter = true, bool isBKG = false)
{

    std::cout << "Processing config: " << config << std::endl;
    std::cout << "Data file: " << datafilename << std::endl;
    std::cout << "Event type: " << eventtype << std::endl;
    std::cout << "PID generation file: " << pidgenfilename << std::endl;
    std::cout << "Output file: " << outputfilename << std::endl;
    std::cout << "Filter: " << (filter ? "true" : "false") << std::endl;
    std::cout << "Is BKG: " << (isBKG ? "true" : "false") << std::endl;

    // Determine the preprocessing mode based on eventtype
    const std::string mode = get_preprocess_mode(eventtype);

    // Load the first file and tree
    auto f1 = TFile::Open(datafilename);
    auto t1 = (TTree *)f1->Get("SignalTuple/DecayTree");

    if (strcmp(pidgenfilename, "noPIDcorr") != 0)
    {
        // Load the second file and tree (friend)
        auto f2 = TFile::Open(pidgenfilename);
        auto t2 = (TTree *)f2->Get("DecayTree");

        // Rename the friend tree for clarity
        t2->SetName("pidgen");
        t1->AddFriend(t2);
    }

    // Create RDataFrame from the main tree (t1 with friend t2)
    ROOT::RDataFrame df(*t1);

    // Get all accessible column names (including friend tree)
    auto allCols = df.GetColumnNames();

    // Define aliases for pidgen.* columns without the prefix
    std::vector<std::string> outputCols;
    ROOT::RDF::RNode aliasedDF = df;

    for (const auto &col : allCols)
    {
        if (col.rfind("pidgen.", 0) == 0)
        {
            // Remove "pidgen." prefix
            std::string alias = col.substr(7);
            aliasedDF = aliasedDF.Redefine(alias, col); // alias = col expression
            outputCols.push_back(alias);
        }
        else
        {
            outputCols.push_back(col);
        }
    }

    auto xcselectDF = add_Xc_Selection(aliasedDF, mode.c_str(), pidgenfilename, isBKG);
    std::string added_col = "Xc_Selection";
    if (isBKG) {
        added_col = "Xc_Selection_BDTbkg";
    }
    // Add the new column to the output columns
    outputCols.push_back(added_col);
        
    // Snapshot with cleaned branch names
    if (filter)
    {
            xcselectDF.Filter(added_col + "==1 && B_MM>5000").Snapshot("DecayTree", outputfilename, outputCols);
    }
    else
    {
        xcselectDF.Snapshot("DecayTree", outputfilename, outputCols);
    }
}
