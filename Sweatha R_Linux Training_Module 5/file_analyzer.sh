#!/bin/bash
#echo "$$"
#sleep 4 &
#echo "PID of last bg cmd : $!"
#echo "current shell options:$-"
#echo "last arg of prev cmd:$_"

err="error.log"

log_err()
{
	echo "Error :$1" >&2
	echo "Error :$1" >> "$err"
}

help_menu()
{
	cat << EOF
Usage:  [options]

Options:
  -d <directory>   Search for keyword in files in the specified directory and subdirectories.
  -k <keyword>     Keyword to search for in the files.
  -f <file>        Search for keyword in the specified file.
  --help           Display this help menu.

Examples:
  $0 -d logs -k error    Search for the keyword "error" in the logs directory and its subdirectories.
EOF
}

validate(){
local k="$1"
local f="$2"
local pt='^[a-zA-Z_]+$'
if [[ -z "$k" || ! "$k" =~ $pt ]]; then
	log_err "Invalid keyword"
	return 1

fi

if [[ -n "$f" && ! -f "$f" ]]; then
	echo "$f does not exist"
	return 1
fi


	return 0

}

search(){
local dir="$1"
local k1="$1"
if [[ -d "$dir" ]]; then
	for file in "$dir"/*; do
		if [[ -d "$file" ]]; then
			search "$file" "$k1"

		elif [[ -f "$file" ]]; then
			if grep -q "$k" "$file"; then
				echo "match found"
			fi
		fi
	done

else
	log_err "dir does not exist - $dir"
fi
			
}
if [[ "$1" == "--help" ]]; then
        help_menu
        exit 0
fi

while getopts ":d:k:f:" fg; do
	case "$fg" in
		d) 
			dir="$OPTARG"
		;;
		k) 
			key="$OPTARG"
		;;
		f) 
			file="$OPTARG"
		;;
		*)
			log_err  "Invalid input check usage by giving "$0" --help"
			exit 1
		;;

	esac
done


if [[ -n "$dir" && -n "$file" ]];then
	log_err "Cannot have both dir and file at the same time"
	exit 1
fi

if  ! validate "$key" "$file";then
	log_err "Invalid inputs $1 , $2"
       	exit 1
fi

if [[ -n "$dir" ]]; then
	search "$dir" "$key"
elif [[ -n "$file" ]]; then
	if grep -q "$key" "$file"; then
		echo "Keyword "$key" found in file "$file""
		
	else
		echo "No match found"
	fi
else
	log_err "Neither a dir or file is specified"
	exit 1
fi

echo "Script name:$0"
echo "Tot Arg:$#"
echo "Exit code of prev cmd:$?"
echo "All arg:$@"



