/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool search(int arr[3][3],int key,int n)
{
    int r=0;
    int c=n-1;
    while(r<n && c>=0)
    {
        if(arr[r][c]==key)
        {
            printf("r- %d , c- %d ",r,c);
            return true;
        }
        else if(arr[r][c]>key)
        {
            c--;
           
        }
        else
        {
            r++;
            
        }
    }
    return false;
    
}
int main()
{
    int arr[3][3]={
        {1,3,4},
        {5,7,9},
        {11,13,15}
    };
    int key=21;
    int n=3;
    if(search(arr,key,n)==true)
    {
        printf("key %d is found\n",key);
    }
    else
    {
        printf("key %d is not found\n",key);
    }
    return 0;
}
