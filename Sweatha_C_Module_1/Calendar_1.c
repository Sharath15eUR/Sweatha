#include <stdio.h>
#include <string.h>

#define MAX_DAYS 7
#define MAX_TASKS 3
#define MAX_TASK_LENGTH 100 

struct Day
{
        char name[10];
        int tasks[MAX_TASKS][MAX_TASK_LENGTH];
}
int main()
{       
       struct Day week[MAX_DAYS]=
       {
           {"Monday",{"","",""}},
           {"Tuesday",{"","",""}},
           {"Wednesday",{"","",""}},
           {"Thursday",{"","",""}},
           {"Friday",{"","",""}},
           {"Saturday",{"","",""}},
           {"Sunday",{"","",""}}
       }
       int ch;
       do
       {
           scanf("%d",&ch);
           switch(ch)
           {
               case 1:
                add_Tasks(week,MAX_DAYS);
           }
       } while(ch!=3);
       
       return 0;
}    
