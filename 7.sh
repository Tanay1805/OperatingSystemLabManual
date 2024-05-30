#!/bin/zsh

# Find all files with .tmp extension and delete them
find . -type f -name "*.tmp" -delete

echo "Deleted all files with .tmp extension."
