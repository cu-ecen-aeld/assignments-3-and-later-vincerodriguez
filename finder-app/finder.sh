#!/usr/bin/env bash

filesdir="$1"
searchstr=$2


if [ $# -lt 2 ]; then
    echo "Usage: $0 <directory> <searchstring>"
    exit 1
fi

if [ ! -d "$filesdir" ]; then 
    echo "Directory $1 does not exist"
    exit 1
fi

#grep -rl: recursive search all subdirectories and list only the file names and piping into wc -l effectively counts number of files 
NUM_FILES=$(grep -rl "$searchstr" "$filesdir" 2> /dev/null | wc -l )

#grep -r: recursively search all subdirectories and list all lines with matching string and pipe into wc to count number of lines 
NUM_LINES=$(grep -r "$searchstr" "$filesdir" 2> /dev/null | wc -l )



echo "The number of files are $NUM_FILES and the number of matching lines are $NUM_LINES"


