#!/bin/bash

# $1: contest_id (e.g. abc100)

if [ $# -ne 1 ]; then
    echo "Usage: $0 <contest_id>"
    exit 1
fi

CONTEST_ID=$1
BASE_DIR="src/atcoder/abc"
TARGET_DIR="${BASE_DIR}/${CONTEST_ID}"
TEMPLATE="templates/atcoder.cpp"

if [ ! -d "$BASE_DIR" ]; then
    mkdir -p "$BASE_DIR"
fi

cd "$BASE_DIR"
acc new "$CONTEST_ID"

# Check if creation was successful
if [ ! -d "$CONTEST_ID" ]; then
    echo "Failed to create contest directory."
    exit 1
fi

cd "$CONTEST_ID"

# Copy template to each problem directory
for dir in */; do
    # Remove trailing slash
    problem_dir=${dir%/}
    # Problem ID is usually the directory name (a, b, c...)
    # We want file name like abc100_a.cpp
    
    # Destination file path
    dest_file="${problem_dir}/${CONTEST_ID}_${problem_dir}.cpp"
    
    # Check if file already exists to avoid overwriting
    if [ ! -f "$dest_file" ]; then
        # Copy template (assuming script is run from project root, so we need absolute or relative path to template)
        # We changed directory, so we need to reference template correctly.
        # simpler to use absolute path for template or adjust relative path.
        # We are in src/atcoder/abc/$CONTEST_ID
        # Template is in ../../../../templates/atcoder.cpp
        
        cp -n "../../../../$TEMPLATE" "$dest_file"
        echo "Created $dest_file"
    else
        echo "Skipped $dest_file (already exists)"
    fi
done

echo "Download and setup complete for $CONTEST_ID"
