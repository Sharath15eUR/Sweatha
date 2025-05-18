#include <stdio.h>
#include <string.h>

#define MAX_DAYS 7
#define MAX_TASKS 3
#define MAX_TASK_LENGTH 100 

struct Day
{
        char name[10];
        char tasks[MAX_TASKS][MAX_TASK_LENGTH];
};


void inputTasks(struct Day week[],int total_days)
{
     int found=0;
     char inputDay[10];
     printf("Enter the day you want to add task\n");
     scanf("%s",inputDay);
     for(int i=0;i<total_days;i++)
     {
         if(strcmp(week[i].name,inputDay)==0)
         {
             found=1;
             printf("ENter the 3 tasks for the day: \n");
             for(int j=0;j<MAX_TASKS;j++)
             {
                 printf("ENter the task of day %d\n",j+1);
                 scanf(" %[^\n]",week[i].tasks[j]);
             }
             break;
         }
     }
     if(!found)
     {
         printf("INvalid day entered\n");
     }
   
    
    
}

void display_Tasks(struct Day week[],int total_days)
{
    for(int i=0;i<total_days;i++)
    {
        printf("%s : \n",week[i].name);
        for(int j=0;j<MAX_TASKS;j++)
        {
            if(strlen(week[i].name)>0)
                printf("%s \n",week[i].tasks[j]);
        }
        
    }
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
       };
       int ch;
       do
       {
           printf("1.Add tasks\n");
           printf("2.Display tasks\n");
           printf("3.Exit\n");
           printf("ENter your option\n");
           scanf("%d",&ch);
           switch(ch)
           {
               case 1:{
                inputTasks(week,MAX_DAYS);
                break;}
               case 2:{
                display_Tasks(week,MAX_DAYS);
                break;}
               case 3:
                printf("Exitting the program\n");
               default:
                printf("ENter a valid option\n");
            
           }
       } while(ch!=3);
       
       return 0;
}    
