import nbformat
import os

# Specify the directory path
directory_path = '../eos/lhcb/wg/semileptonic/RDsHad/AP/v2/ap_moreinfopid/'

# List all files with the .root extension in the specified path
try:
    # List all entries in the directory
    files_and_dirs = os.listdir(directory_path)

    # Filter out directories and non-.root files
    root_files = [os.path.abspath(os.path.join(directory_path, f)) for f in files_and_dirs if f.endswith('.root') \
                  and os.path.isfile(os.path.join(directory_path, f))]
    # Print the list of .root files
    for file in root_files:
        print(file)
except FileNotFoundError:
    print(f"The directory {directory_path} does not exist.")
except Exception as e:
    print(f"An error occurred: {e}")

    
# Load the existing notebook
with open('CheckProcessedInput.ipynb', 'r', encoding='utf-8') as f:
    notebook = nbformat.read(f, as_version=4)

    
for f in root_files:
    
    if notebook.cells:
        # Change the first cell's content
        notebook.cells[0].source = f"filename='{f}'"

    # Save the modified notebook to a new file
    f2name = f'Check_{os.path.basename(f)}.ipynb'
    with open(f2name, 'w', encoding='utf-8') as f:
        nbformat.write(notebook, f)

    print(f"Notebook modified and saved as {f2name}.ipynb")
