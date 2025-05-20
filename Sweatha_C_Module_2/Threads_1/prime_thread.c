#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


int g_N;

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

void* A_func_thread(void* arg)
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
    return NULL;
}

void* B_func_thread(void* arg)
{
    time_t start_time = time(NULL);
    while(difftime(time(NULL),start_time)<100)
    {
        printf("Thread B is running successfully\n");
        sleep(2);
    }
    return NULL;
    
}

void* C_func_thread(void* arg)
{
    time_t start_time = time(NULL);
    while(difftime(time(NULL),start_time)<100)
    {
        printf("Thread C is running successfully\n");
        sleep(3);
    }
    return NULL;
    
}

int main()
{
    pthread_t tA,tB,tC;
    
    printf("Enter the value of N ");
    scanf("%d",&g_N);
    
    
    pthread_create(&tA,NULL,A_func_thread,NULL);
    pthread_create(&tB,NULL,B_func_thread,NULL);
    pthread_create(&tC,NULL,C_func_thread,NULL);
    
    
    pthread_join(tA,NULL);
    pthread_join(tB,NULL);
    pthread_join(tC,NULL);
    
    return 0;
}
