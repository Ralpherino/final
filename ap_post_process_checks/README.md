Workflow to produce reports on the RDsHad ntuples
=================================================

Should be run using the LHCb *lb-conda default* environments, with latex available
To get this, from a host with the LHCb environment (e.g. on lxplus)
```
lb-conda --texlive default/2023-04-26
```

To run the workflow itself:
```
./run
```

the file *config/config.json* can be customized to specify the temporary storage and where to write the output.