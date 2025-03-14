writefile="$1"
writestr="$2"

if [ $# -lt 2 ]; then 
    echo "Usage: $0 <writedirectory> <writestring>" 
    exit 1
fi 


touch "$1"
echo "$writestr" > "$1" 
