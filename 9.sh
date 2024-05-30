#!/bin/zsh

# Define the directory containing the text files
txt_dir="/path/to/text_directory"

# Check if the directory exists
if [[ -d "$txt_dir" ]]; then
    # Rename all .txt files to .bak
    for file in $txt_dir/*.txt; do
        if [[ -f "$file" ]]; then
            new_name="${file%.txt}.bak"
            mv "$file" "$new_name"
            echo "Renamed $file to $new_name"
        fi
    done
else
    echo "Directory '$txt_dir' not found."
fi
