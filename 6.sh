#!/bin/zsh

# Iterate over files in the current directory
for file in *; do
    # Check if the file is a regular file (not a directory)
    if [[ -f $file ]]; then
        # Get the size of the file
        size=$(stat -c "%s" "$file")
        # Print the filename and size
        echo "$file: $size bytes"
    fi
done
