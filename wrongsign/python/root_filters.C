/*
 * Tools to check the ancestors of the pions in the R(Ds) ntuple
 */

/** Global verbosity level, do not enable in jobs... */
bool rds_verbose = false;

/************************** DGeneral utilities **************************/


/**
 * Utility to find a value repeated 3 times on a sorted list
 * (extension of std::adjacent_find)
 */
template <class ForwardIt>
ForwardIt adjacent3_find(ForwardIt first, ForwardIt last)
{
    if (first == last)
    {
        return last;
    }
    ForwardIt next = first + 1;
    if (next == last)
    {
        return last;
    }
    ForwardIt nextnext = next + 1;

    for (; nextnext != last; ++next, ++nextnext, ++first)
    {
        if (*first == *next && *first == *nextnext)
        {
            return first;
        }
    }
    return last;
}

/************************** Methods to process RVec<float> in TTree **************************/

/**
 * Check whether the 3 arrays contain common ancestors
 */
bool same_mother3(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return p1[0] == p2[0] && p1[0] == p3[0];
}

/**
 * Check whether the 3 arrays contain common ancestors
 */
bool have_common_parents3(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{

    std::vector<Float_t> keys;
    keys.reserve(p1.size() + p2.size() + p3.size());
    auto notzero = [](Float_t x)
    { return x != 0; };
    std::copy_if(p1.begin(), p1.end(), std::back_inserter(keys), notzero);
    std::copy_if(p2.begin(), p2.end(), std::back_inserter(keys), notzero);
    std::copy_if(p3.begin(), p3.end(), std::back_inserter(keys), notzero);

    std::sort(keys.begin(), keys.end());

    auto adjacent = adjacent3_find(keys.begin(), keys.end());
    bool found = (adjacent != keys.end());

    if (rds_verbose)
    {
        std::cout << p1 << std::endl;
        std::cout << p2 << std::endl;
        std::cout << p3 << std::endl;

        std::cout << "Found: " << found;
        if (found)
        {
            std::cout << " " << *adjacent;
        }
        std::cout << std::endl;
        std::cout << keys.size() << " > ";
        for (const auto &v : keys)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
        std::cout << "###################################" << std::endl;
    }
    return found;
}

/**
 * Check whether the 3 arrays contain common ancestors
 */
bool have_common_parents6(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3,
                          ROOT::VecOps::RVec<Float_t> p4, ROOT::VecOps::RVec<Float_t> p5, ROOT::VecOps::RVec<Float_t> p6)
{

    std::unordered_map<Float_t, unsigned int> rv;
    auto lists = {p1, p2, p3, p4, p5, p6};
    for (auto p : lists)
    {
        for (auto val : p)
        {
            if (val != 0)
                rv[val]++;
        }
    }

    bool found = false;
    for (auto &it : rv)
    {
        if (it.second == 6)
        {
            found = true;
            break;
        }
    }

    if (rds_verbose)
    {
        std::cout << p1 << std::endl;
        std::cout << p2 << std::endl;
        std::cout << p3 << std::endl;
        std::cout << p4 << std::endl;
        std::cout << p5 << std::endl;
        std::cout << p6 << std::endl;
        std::cout << "Found: " << found << std::endl;
        for (const auto &v : rv)
        {
            std::cout << v.first << " : " << v.second << std::endl;
        }
        std::cout << "###################################" << std::endl;
    }
    return found;
}

/**
 * Check whether the 3 arrays contain common ancestors
 */
bool from_id(ROOT::VecOps::RVec<Float_t> p, Float_t pid)
{
    Float_t apid = abs(pid);
    auto top = std::find_if(begin(p), end(p), [&apid](Float_t x)
                            { return abs(x) == apid; });
    if (top == end(p))
    {
        return false;
    }
    return true;
}

bool from_id3(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3, Float_t pid)
{
    return from_id(p1, pid) && from_id(p2, pid) && from_id(p3, pid);
}

bool from_B0(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 511);
}

bool from_Bp(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 521);
}

bool from_Bs(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 531);
}

bool from_Bsst(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 533);
}

bool from_Bc(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 5341);
}

bool from_LambdaB(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 5122);
}

bool from_ChiB(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 5132);
}

bool from_pi0(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 111);
}

bool from_gamma(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return from_id3(p1, p2, p3, 22);
}

bool all_pions(Float_t  p1, Float_t p2, Float_t p3)
{   
    return (std::abs(p1) == 211)  && (std::abs(p2) == 211) && (std::abs(p3) == 211);
}

/**
 * Check whether the ancestor list contains a particle with the specific ID
 */
Float_t decay_top(ROOT::VecOps::RVec<Float_t> p, int rank = 1)
{
    auto top = std::find(begin(p), end(p), 0);
    if (top == end(p) || top == begin(p))
    {
        return 0;
    }
    return *(top - rank);
}

/************************** Tools to deal with diffVertex **************************/

// List of long lived particles taken from scikit-hep
std::vector<Float_t> long_lived{11, 12, 13, 14, 15, 16, 21, 22, 130, 211, 310, 321, 411, 421, 431, 511, 521, 531, 541, 2112, 2212, 3112, 3122, 3222, 3312, 3322, 3334, 4122, 4132, 4232, 4332, 5122, 5132, 5232, 5332};


/**
 * Filter a list of ancestors to return the long lived ones
 * Version that updates a RVec passed
 */
void filter_long_lived1(const ROOT::VecOps::RVec<Float_t> &initial, ROOT::VecOps::RVec<Float_t> &filtered)
{
    std::copy_if(initial.begin(), initial.end(), 
                std::back_inserter(filtered), [](Float_t id){ 
                    auto absid = std::abs(id);
                    return  (std::find(long_lived.begin(), long_lived.end(), absid) != long_lived.end());
                } );
    // std::abs on all elements
    std::transform(filtered.begin(), filtered.end(), filtered.begin(), [](Float_t id){ return std::abs(id);});
}

/**
 * Filter a list of ancestors to return the long lived ones and prepend with the TRUEID of the particle
 * (the order is reversed)
 * Version that returns a RVec
 */
ROOT::VecOps::RVec<Float_t> build_LL_decay(const ROOT::VecOps::RVec<Float_t> &initial, Int_t trueid)
{
    ROOT::VecOps::RVec<Float_t> filtered;
    filtered.reserve(initial.size() +1);
    filtered.emplace_back((Float_t)trueid);
    std::copy_if(initial.begin(), initial.end(), 
                std::back_inserter(filtered), [](Float_t id){ 
                    auto absid = std::abs(id);
                    return  (std::find(long_lived.begin(), long_lived.end(), absid) != long_lived.end());
                } );
    // std::abs on all elements
    std::transform(filtered.begin(), filtered.end(), filtered.begin(), [](Float_t id){ return std::abs(id);});
    return filtered;
}

/* Various predicates for data filtering */
struct IsCharm {
    bool operator() (Float_t pid) {
        return ((pid >=400 && pid < 500) || (pid >=4000 && pid < 5000) );
    }
};

struct IsStrange {
    bool operator() (Float_t pid) {
        return ((pid >=300 && pid < 400) || (pid >=4000 && pid < 4000) );
    }   
};

struct IsBeauty {
    bool  operator() (Float_t pid) {
        return ((pid >=500 && pid < 600) || (pid >=5000 && pid < 6000) );
    }
};


/**
 * @brief Return the number of branches with charm in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int
 */
template <typename UnaryPredicate>
int _count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3, UnaryPredicate pred)
{
    int count = 0;
    std::array< ROOT::VecOps::RVec<Float_t>, 3> parts{p1, p2, p3};
    for(const auto &p: parts) {
        if (std::any_of(p.begin(), p.end(), pred)) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Return the number of branches with charm in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int 
 */
int charm_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return _count(p1, p2, p3, IsCharm());
}

/**
 * @brief Return the number of branches with strange particles in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int 
 */
int strange_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return _count(p1, p2, p3, IsStrange());
}

/**
 * @brief Return the number of branches with beauty particles in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int 
 */
int beauty_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return _count(p1, p2, p3, IsBeauty());
}

/**
 * @brief Return the number of branches with a tau in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int 
 */
int tau_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return _count(p1, p2, p3,[] (Float_t pid){ return pid == 15;});
}

/**
 * @brief Return the number of branches with a tau in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int 
 */
int Bc_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3)
{
    return _count(p1, p2, p3,[] (Float_t pid){ return pid == 541;});
}

/**
 * @brief Return the number of branches with charm in the ancestry
 * 
 * @param p1 ancestors of first pion
 * @param p2 ancestors of second pion
 * @param p3 ...
 * @return int
 */
template <typename UnaryPredicate>
int _apply_predicate(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3, UnaryPredicate pred)
{
    int count = 0;
    std::array< ROOT::VecOps::RVec<Float_t>, 3> parts{p1, p2, p3};
    for(const auto &p: parts) {
        if (pred(p)) {
            count++;
        }
    }
    return count;
}

int photon_conversion_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3) {
    return _apply_predicate(p1, p2, p3, [](ROOT::VecOps::RVec<Float_t> p) {
        std::array<Float_t, 2>  tofind{11, 22};
        return std::search(p.begin(), p.end(), tofind.begin(), tofind.end()) != p.end();
    });
}

int pion_material_interaction_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3) {
    return _apply_predicate(p1, p2, p3, [](ROOT::VecOps::RVec<Float_t> p) {
        std::array<Float_t, 2>  tofind{211, 211};
        return std::search(p.begin(), p.end(), tofind.begin(), tofind.end()) != p.end();
    });
}

int pion_decay_count(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3) {
    return _apply_predicate(p1, p2, p3, [](ROOT::VecOps::RVec<Float_t> p) {
        std::array<Float_t, 2>  tofind{13, 211};
        return std::search(p.begin(), p.end(), tofind.begin(), tofind.end()) != p.end();
    });
}
/**
 * @brief Create all columns linked to the decay view with only long lived particles
 * 
 * @param df The dataframe to be updated
 */
 ROOT::RDF::RNode define_LL_columns(ROOT::RDataFrame df) {

    // Filtering the main PANC_IDs columns
    auto dfb = df.Define("LL_p1_fromY_PANC_IDs", build_LL_decay, {"p1_fromY_PANC_IDs", "p1_fromY_TRUEID"})
                 .Define("LL_p2_fromY_PANC_IDs", build_LL_decay, {"p2_fromY_PANC_IDs", "p2_fromY_TRUEID"})
                 .Define("LL_p3_fromY_PANC_IDs", build_LL_decay, {"p3_fromY_PANC_IDs", "p3_fromY_TRUEID"});
    
    // Extra columns
    auto dff = dfb.Define("LL_charmcount", charm_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_strangecount", strange_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_beautycount", beauty_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_taucount", tau_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_Bccount", Bc_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_photon_conversion_count", photon_conversion_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_pi_matinter_count", pion_material_interaction_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"})
                   .Define("LL_pi_decay_count", pion_decay_count, 
                          {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs"});

    return dff;
}


/************************** DEBUGGING **************************/

/**
 * debug method
 */
bool debug_LL(ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3, 
           int cc, int sc, int bc, int tc, int bcc, int photconv, int pimatint, int pidec)
{
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << "Charmcount:" << cc << std::endl;
    std::cout << "Strangecount:" << sc << std::endl;
    std::cout << "Beautycount:" << bc << std::endl;
    std::cout << "Taucount:" << tc << std::endl;
    std::cout << "Bccount:" << bcc << std::endl;
    std::cout << "Photconv:" << photconv << std::endl;
    std::cout << "pimatint:" << pimatint << std::endl;
    std::cout << "pidec:" << pidec << std::endl;
    std::cout << "###################################" << std::endl;
    return true;
}

/**
 * Main method of the script, useful for debugging only
 */
void root_filters()
{
    ROOT::RDataFrame df("DecayTree", "../../inclusive_MC/categories3/study_variables_category/MC_2012_Ds3piX_PIDcorr_withMOREinfo_BDTcut_diffVertex.root");
    auto df2 = define_LL_columns(df);

    df2.Foreach([](ROOT::VecOps::RVec<Float_t> p1, ROOT::VecOps::RVec<Float_t> p2, ROOT::VecOps::RVec<Float_t> p3, 
                int cc, int sc, int bc, int tc, int bcc, int photconv, int pimatint, int pidec)
               { std::cout << debug_LL(p1, p2, p3, cc, sc, bc, tc, bcc, photconv, pimatint, pidec) << std::endl;},
               {"LL_p1_fromY_PANC_IDs", "LL_p2_fromY_PANC_IDs", "LL_p3_fromY_PANC_IDs", 
               "LL_charmcount", "LL_strangecount", "LL_beautycount", "LL_taucount", "LL_Bccount", 
               "LL_photon_conversion_count", "LL_pi_matinter_count", "LL_pi_decay_count"});

    // auto df2 = df.Define("p_fromY_PANC_commonAncestor", have_common_parents3, {"p1_fromY_PANC_Keys", "p2_fromY_PANC_Keys", "p3_fromY_PANC_Keys"});
    // auto df3 = df.Define("XcY_PANC_commonAncestor", have_common_parents6, {"p1_fromY_PANC_Keys", "p2_fromY_PANC_Keys", "p3_fromY_PANC_Keys", "p1_fromXc_PANC_Keys", "p2_fromXc_PANC_Keys", "p3_fromXc_PANC_Keys"}); 
    //auto df4 = df.Define("p1_fromY_PANC_IDs_LL", filter_long_lived2, {"p1_fromY_PANC_IDs"});
    // df4.Foreach([](ROOT::VecOps::RVec<Float_t> s)
    //            { std::cout << debug(s) << std::endl;},
    //            {"p1_fromY_PANC_IDs_LL"});
    // df.Foreach([](ROOT::VecOps::RVec<Float_t> s)
    //            { std::cout << s << std::endl; },
    //            {"p1_fromY_PANC_IDs"});

    // df3.Foreach([](bool s)
    //              { std::cout << s << std::endl; },
    //              {"XcY_PANC_commonAncestor"});
    
}
