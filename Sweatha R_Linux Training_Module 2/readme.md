SOLUTIONS

1)$ find -type f -size +1M
  -'find' cmd is to find the files having the criteria satisfied
  -'-type f' looks for files only
  -'-size' is to look for the size parameter of the files
  -'+1M' indicates files having larger than 1MB

2)$ sed 's/localhost/127.0.0.1/g' config.txt>updated_config.txt
  -'sed' is stream editor which used to do many text manipulation
  -'s' is for substitution and it changes the word 'localhost' to '127.0.0.1' 
  -'g' is for changing all the occurences 

3)$ grep "ERROR" log.txt |grep -v "DEBUG" > filtered_log.txt
  -'grep' is to find a specific text pattern
  -'-v' is used to perform an exception in the filtered text

4)$ PID_VAR=$(ps aux --sort -%mem |awk 'NR==2 {print $2}')
  $ kill PID_VAR
  -'%mem' used to sort based on the memory usage and '-' before %mem is for making a descending sort
  -'NR' is for accessing the number of records, here the second row has the output of high memory usage process
  -'$2' is for getting the process id to kill it 

5)$ ip route | grep default |awk '{print $3}'|sort -u
  -'ip route' is to get the routing table information
  -'default' is to fetch the default gateways
  -'$3' is for getting the gateway ip address
  -'sort -u' used to sort the ip and give the one's which are unique
