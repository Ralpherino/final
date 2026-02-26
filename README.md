# RDs Hadronic workflows

## Tools and workflows

### general structure and data access

The codebase is split in a number of different sub-parts corresponding to various steps in
the processing, or to various checks of the data.

The processing is organized as a set different `Snakemake` workflows, which produces files in CERN EOS, in
```
"root://eoslhcb.cern.ch//eos/lhcb/wg/semileptonic/RDsHad/AP/final/
```

Potential output of the sub-parts is stored in a sub-folder in EOS, such as

```
/eos/lhcb/wg/semileptonic/RDsHad/AP/final/ap_post_process
```

Inside that folder, 2 sub-folders can be found, such as `output` which is where Snakemake directly produces the files.
Another folder, intitulated `validated` contains a previous iteration of the `output` folder that was validated 
and discussed with other team members.

**N.B. this structure with `output`/`validated` was put in place to avoid overwriting accidentally the analysis files as `Snakemake` first clears the targets before processing the input.**


### ap_post_process

This workflow processes the Analysis Production data for the sl/rds_hadronic analysis.
Based on the analysis production, it:
- creates extra variables needed for the analysis
- applies the 3 BDTs Bs, Ds and 3pi
- add corrected kinematic quantities with PIDGen
- apply code to categorise the candidates using the logic implemented in `categories4.py`
- filters the candidates based on the BDT outputs

### ap_post_process_checks

Notebooks with various checks on the data produced by the `ap_post_process` workflow.

### ap_post_process_data

Extra workflows to process output of the Analysis Production.
**Not needed any more, should be removed after checks**

### common

Various commin files used in the processing of the data.

### crosschecks

Studies on the data, e.g. the vertex separation, the lifetime of the tau etc...

### data_mc_comparison

Notebooks with comparisons between data and MC

### export_templates

Workflows to export the fit templates.

### review_comments

Notebooks adressing various review comments.

### train_bdt

Tools to train the BDT to suppress double charm decays background, using the `xgboost` library.

### validate_categories

Validation of the chosen categorization of the candidates

### wrongsign

Unsuccessful attemps to use wrong sign sample to derive the shape of the combinatorics (due to double charm background).

## How to run the workflows

Environment to use by default:  lb-conda default/2023-04-26
Some workflows, e.g. for pidgen use different environments. 

## Fitting the various categories

Implemented in (the rdshadfit project)[https://gitlab.cern.ch/lhcb-rdshad/rdshadfit]
test
