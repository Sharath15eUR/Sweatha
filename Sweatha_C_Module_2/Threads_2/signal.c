#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


int g_N;

/*

handle_int function to prevent 
abrupt termination of process 
when ctrl+c is entered by the user

**/

void handle_int(int sig)
{
    printf("signal %d caught\n",sig);
}

bool is_prime(int n)
{
    if(n<2)
    {
        return false;
    }
    else
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
    }
    return true;
}

void A_func()
{
    int n=2,sum=0,c=0;
    
    while(c<g_N)
    {
       if(is_prime(n))
       {
           sum+=n;
           c++;
       }
       n++;
    }
    
    printf("The sum of first %d prime numbers : %d\n",g_N,sum);
   
}

void B_func()
{
    time_t start_time = time(NULL);
    time_t begin=start_time;
    while(difftime(time(NULL),begin)<100)
    {
        printf("Thread B is running successfully\n");
        sleep(2);
    }
    time_t end_time = time(NULL);
    printf("B_func is executed in duration : %ld\n",end_time - start_time);
   
    
}

void C_func()
{
    time_t start_time = time(NULL);
    time_t begin=start_time;
    while(difftime(time(NULL),begin)<100)
    {
        printf("Thread C is running successfully\n");
        sleep(3);
    }
    time_t end_time = time(NULL);
    printf("C_func is executed in duration : %ld\n",end_time - start_time);
   
    
}

int main()
{
    signal(SIGINT,handle_int);
    
    printf("Enter the value of N ");
    scanf("%d",&g_N);
    A_func();
    B_func();
    C_func();   
    
   
    
    return 0;
}
