module 1 assignment questions

1) Create a file and add executable permission to all users (user, group and others)
2) create a file and remove write permission for group user alone.
3) Create a file and add a softlink to the file in different directory (Eg : Create a file in dir1/dir2/file and create a softlink for file inside dir1)
4) Use ps command with options to display all active process running on the system
5) Create 3 files in a dir1 and re-direct the output of list command with sorted by timestamp of the files to a file



I have shared the answers of module 1 assignments.In screenshots folder i have the op screenshot of all the commands . And I have created text files for question 1,2 and 4  and folders for q3 and 5 .

I will also explain the commands that i have used and why for each of the question here:

Ans:

1)$touch file1
    -to create a file
  $chmod a+x file1
    -'chmod' is used to modify the permissions to a file or dir
    -'a' is for giving permission to all users-[user,group,others]
    -'+' is for adding permission
    -'x' is for giving the executable permission

2)$touch file2- to create a file
  $chmod g-w file2
    -'chmod' is used to modify the permissions to a file or dir
    -'g' is for denoting the group users
    -'-'is for removing the permission
    -'w'is for modifying writing access

3)$mkdir -p dir1/dir2
    -create a directory dir1,dir2 
    -'-p' indicates if the parent dir not exist , it will create one without raising any error
    -'dir1' is the parent dir and 'dir2' is the subdirectory inside dir1
  $touch dir1/dir2/file3
    -create a file inside 'dir2' directory
  $ln -s dir1/dir2/file3 dir1/file3_link
    -create a link to file3 inside dir1
    -'ln' is used to create a link for files
    -'-s'is for creating soft/symbolic links . By default it will create hard link. Hard links are like a copy of the file we are linking if we delete the original file still the     copy file exist. Soft links are like a pointer to the original file ,while deleting the original file affects the link file.
    
    
4)$ps -aux
    -'ps' is used to retrieve information about the currently running process
    -'a' is used to collect details about all the users process.
    -'u' is used to display the user details along with process like user name etc
    -'x' is used to display process without controllable terminal too
    
    
    
5)$touch dir1/file5_1 dir1/file5_2 dir1/file5_3
    -'create 3 files inside dir1'
  $ls -lt dir1 > dir1/op.txt
    -'ls' list the contents
    -'l' is for giving detailed long content 
    -'t' is for sorting the file with respect to the timestamp in descending order
    -'>'redirects the content details of dir1 to a text file 'op.txt'


