#!/bin/bash

# $1: contest_id (e.g. arc100)

if [ $# -ne 1 ]; then
    echo "Usage: $0 <contest_id>"
    exit 1
fi

CONTEST_ID=$1
BASE_DIR="src/atcoder/arc"
TARGET_DIR="${BASE_DIR}/${CONTEST_ID}"
TEMPLATE="templates/atcoder.cpp"

if [ ! -d "$BASE_DIR" ]; then
    mkdir -p "$BASE_DIR"
fi

cd "$BASE_DIR"
acc new "$CONTEST_ID"

if [ ! -d "$CONTEST_ID" ]; then
    echo "Failed to create contest directory."
    exit 1
fi

cd "$CONTEST_ID"

for dir in */; do
    problem_dir=${dir%/}
    dest_file="${problem_dir}/${CONTEST_ID}_${problem_dir}.cpp"
    
    if [ ! -f "$dest_file" ]; then
        cp -n "../../../../$TEMPLATE" "$dest_file"
        echo "Created $dest_file"
    else
        echo "Skipped $dest_file (already exists)"
    fi
done

echo "Download and setup complete for $CONTEST_ID"
