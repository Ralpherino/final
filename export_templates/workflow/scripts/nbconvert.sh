#!/bin/bash

# Util to convert the notebook to PDF
# Equivalent to:
# "OUTDIR=$(dirname {output.pdf}) && "
# "mkdir -p $OUTDIR && "
# "jupyter nbconvert --to pdf {input.notebook} "
# "  --ExecutePreprocessor.kernel_name=python3 --ExecutePreprocessor.enabled=True "
# " --output-dir=$OUTDIR "

INPUT=$1
OUTPUT=$2

OUTDIR=$(dirname ${OUTPUT})
mkdir -p $OUTDIR

jupyter nbconvert --to pdf ${INPUT} --ExecutePreprocessor.kernel_name=python3 --ExecutePreprocessor.enabled=True --output-dir=${OUTDIR}