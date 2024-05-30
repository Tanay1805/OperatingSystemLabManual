#!/bin/zsh

# Function to create a backup of a directory
backup_directory() {
    local source_dir="$1"
    local backup_dir="$2"
    local timestamp=$(date +'%Y%m%d%H%M%S')

    # Check if source directory exists
    if [[ ! -d "$source_dir" ]]; then
        echo "Source directory '$source_dir' not found."
        return 1
    fi

    # Check if backup directory exists, if not, create it
    if [[ ! -d "$backup_dir" ]]; then
        mkdir -p "$backup_dir"
    fi

    # Create backup directory with timestamp
    local backup_dest="$backup_dir/backup_$timestamp"
    cp -R "$source_dir" "$backup_dest"

    echo "Backup created at: $backup_dest"
}

# Prompt user to enter source directory path
read -p "Enter the path of the directory to backup: " source_directory

# Prompt user to enter backup directory path
read -p "Enter the path where you want to store the backup: " backup_directory

# Call the function to create backup
backup_directory "$source_directory" "$backup_directory"
