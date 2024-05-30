#!/bin/zsh

# Define the directory containing the log files
log_dir="/path/to/log_directory"

# Check if the directory exists
if [[ -d "$log_dir" ]]; then
    # Use the `tail` command to display the last 20 lines of each .log file
    for file in $log_dir/*.log; do
        if [[ -f "$file" ]]; then
            echo "Last 20 lines of $file:"
            tail -n 20 "$file"
            echo "--------------------------------------------------"
        fi
    done
else
    echo "Directory '$log_dir' not found."
fi
