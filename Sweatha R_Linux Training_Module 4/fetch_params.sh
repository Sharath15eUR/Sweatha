#!/bin/bash

if [[ $# -ne 1 ]]; then
	echo "Provide the input file"
	exit 1
fi

ip_file=$1
op="op.txt"

fr_time=""
wlan_type=""
wlan_subtype=""
> $op

fetch(){
	local ip=$1
	local key=$2
	echo "$ip"|grep -oP "\"$key\": \"\K[^\"]+"
}


while IFS= read -r line; do
	case $line in
		*"frame.time"*)
			fr_time=$(fetch "$line" "frame.time")
			;;
		*"wlan.fc.type"*)
			wlan_type=$(fetch "$line" "wlan.fc.type")
			;;
		*"wlan.fc.subtype"*)
			wlan_subtype=$(fetch "$line" "wlan.fc.subtype")
			;;
	esac

	if [[ -n $fr_time && -n $wlan_type && -n $wlan_subtype ]]; then
		echo "\"frame.time\": \"$fr_time\"," >> $op
		echo "\"wlan.fc.type\": \"$wlan_type\"," >> $op
		echo "\"wlan.fc.subtype\": \"$wlan_subtype\"," >> $op
	fi
done < "$ip_file"

echo "Parameters have been fetched and moved to op file "$op""


		
