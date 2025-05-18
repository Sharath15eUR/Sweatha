#include <stdio.h>


void arrange(int *arr,int size)
{
    for (int *i =arr ; i < arr+size; i++) {
        if(*i % 2 ==0)
        {
            continue;
        }
        int *j=i+1;
        while(j<arr+size && *j%2!=0)
        {
            j++;
        }
        if(j==arr+size)
        {
            break;
        }
        int even=*j;
        for(int *k=j;k>i;k--)
        {
            *k=*(k-1);
        }
        *i=even;
    }
    
}
int main()
{
    int arr[]={1,3,2,5,4,7,6};
    int size=sizeof(arr) / sizeof(arr[0]);
    arrange(arr,size);
    for(int *k=arr;k<arr+size;k++)
    {
      printf("%d ",*k);
  
    }
    
    return 0;
}
