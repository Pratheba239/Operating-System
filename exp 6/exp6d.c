#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int id;
    int arrival_time;
    int bt;
    int wt;
    int tat;
    int remaining_time;
    int completed;
}Process;
int main(){
    int n,quantum;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Enter the quantum time:");
    scanf("%d",&quantum);
    Process processes[n];
    for(int i=0;i<n;i++){
        processes[i].id=i+1;
        printf("Enter the arrival time for Process %d: ",i+1);
        scanf("%d",&processes[i].arrival_time);
        printf("Enter the burst time for Process %d:",i+1);
        scanf("%d",&processes[i].bt);
        processes[i].remaining_time=processes[i].bt;
        processes[i].completed=0;
    }
    int time=0;
    int done=0;
    int total_wt=0,total_tat=0;
    while(done<n){
        int found=0;
        for(int j=0;j<n;j++){
            if(processes[j].arrival_time<=time && processes[j].remaining_time>0){
                found=1;
                if(processes[j].remaining_time>quantum){
                    time+=quantum;
                    processes[j].remaining_time-=quantum;
                }
                else{
                    time+=processes[j].remaining_time;
                    processes[j].wt=time-processes[j].arrival_time-processes[j].bt;
                    processes[j].tat=time-processes[j].arrival_time;
                    processes[j].remaining_time=0;
                    processes[j].completed=1;
                    done++;
                    }
            }
        }
        if(!found){
            time++;
        }
        
    }
    
    for(int i=0;i<n;i++){
        total_tat+=processes[i].tat;
        total_wt+=processes[i].wt;
    }
    printf("Process\tBurst time\tArrival Time\tWaiting time\tTurn around Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",processes[i].id,processes[i].bt, processes[i].arrival_time,processes[i].wt,processes[i].tat);
    }
    printf("Average waiting time : %f",(float)total_wt/n);
    printf("Average turn around time : %f",(float)total_tat/n);
    return 0;
}
