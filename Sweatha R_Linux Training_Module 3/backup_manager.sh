#!/bin/bash

if [ $# -ne 3 ]; then
	echo "Give all the paramenters : source dir , destination dir , file extension"
	exit 1
fi

src_dir=$1
dest_dir=$2
file_ext=$3

if [ ! -d "$src_dir" ]; then
	echo "$src_dir does not exist"
	exit 1 
fi

if [ ! -d "$dest_dir" ]; then
	mkdir -p "$dest_dir"
	if [ $? -ne 0 ]; then
		echo "Destination dir $dest_dir  cannot be created"
		exit 1
	fi
fi

export BACKUP_COUNT=0

files_Arr=("$src_dir"/*"$file_ext")

if [ ${#files_Arr[@]} -eq 0 ]; then
	echo "No files are matching the given extension $file_ext in $dest_dir"
	exit 1
fi

tot_size=0

for file in "${files_Arr[@]}"; do
	if [ -f "$file" ]; then
		fs=$(stat -c "%s" "$file")
		tot_size=$((tot_size+fs))
		echo "$(basename "$file") - $fs bytes"
	fi
done

for file in "${files_Arr[@]}"; do
	if [ -f "$file" ]; then
		dest_file="$dest_dir"/"$(basename "$file")"
		if [ -f "$dest_file" ]; then
			if [ "$file" -nt "$dest_file" ]; then
				cp -p "$file" "$dest_file"
				BACKUP_COUNT=$((BACKUP_COUNT+1))
				
			fi
		else
			cp -p "$file" "$dest_file"
			BACKUP_COUNT=$((BACKUP_COUNT+1))
			
		fi
	fi
done

REPORT_FILE="$dest_dir/backup_report.log"

echo "Back up summary REPORT FILE">"$REPORT_FILE"
echo "TOTAL FILES: $BACKUP_COUNT">>"$REPORT_FILE"
echo "TOTAL SIZE: $tot_size">>"$REPORT_FILE"
echo "Path to Backup dir: $dest_dir">>"$REPORT_FILE"

cat "$REPORT_FILE"

exit 0

