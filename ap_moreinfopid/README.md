Workflow to process RDs Hadronic Analysis production data
=========================================================

Use the apd package to get the list of files from the SL Hadronic_RDs analysis production:
https://lhcb-analysis-productions.web.cern.ch/productions/?wg=sl&analysis=rds_hadronic

This workflow uses PIDGen to recompute PID information, and applies minimal cuts to suppress 
various backgrounds before the data can be used for the RDs analysis.

The workflow should be run using the LHCb *lb-conda default/2025-02-19* environment
(it switches to the *pidgen* environment to actually process the data)

To run:
```
snakemake -j X
```
depending on the number of cores to be used X.

the file *config/config.json* can be customized to specify the temporary storage and where to write the output.