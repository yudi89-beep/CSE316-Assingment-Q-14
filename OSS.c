
#include<stdio.h>
 
int main()
{
    int arrival_time[20],burst_time[20],process[20],waiting_time[20],turn_around[20],priority[20],j,n,total=0,avg_wt,avg_tat;
    printf("Enter Total Number of Processes:\n");
    scanf("%d",&n);
 
    printf("Enter Burst Time and Priority\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\n",i+1);
        printf("Arrival Time:");
        scanf("%d",&arrival_time[i]);
        printf("Burst Time:");
        scanf("%d",&burst_time[i]);
        printf("Priority:");
        scanf("%d",&priority[i]);
        process[i]=i+1;           
    }
 int position,temp;
    
    for(int i=0;i<n;i++)
    {
        position=i;
        for(int j=i+1;j<n;j++)
        {
            if(priority[j]<priority[position])
                position=j;
        }
 
        temp=priority[i];
        priority[i]=priority[position];
        priority[position]=temp;
 
        temp=burst_time[i];
        burst_time[i]=burst_time[position];
        burst_time[position]=temp;
 
        temp=process[i];
        process[i]=process[position];
        process[position]=temp;
    }
 
    waiting_time[0]=0;    

    for(int i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(int j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
 
        total+=waiting_time[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    printf("\nProcess\t\tArrival Time\t\tBurst Time   \tWaiting Time\t\tTurnaround Time");
    for(int i=0;i<n;i++)
    {
        turn_around[i]=burst_time[i]+waiting_time[i];     
        total+=turn_around[i];
        printf("\n P[%d]\t\t  %d\t\t\t%d\t\t    %d\t\t\t%d",process[i],arrival_time[process[i]-1],burst_time[i],waiting_time[i],turn_around[i]);
    }
 
    avg_tat=total/n;     
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    return 0;
}
