#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int process_id;
    int bt;
    int pt;
    int tat;
    int wt;
}Process;
int compare_processes(const void *a,const void *b){
    return ((Process *)a)->pt - ((Process *)b)->pt;
}
int main(){
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    Process processes[n];
    for(int i=0;i<n;i++){
        processes[i].process_id=i+1;
        printf("Enter the burst time for Process %d:",i+1);
        scanf("%d",&processes[i].bt);
        printf("Enter the priority of Process %d:",i+1);
        scanf("%d",&processes[i].pt);
        processes[i].tat=0;
        processes[i].wt=0;
    }
    qsort(processes,n,sizeof(Process),compare_processes);
    int current_time=0;
    for(int i=0;i<n;i++){
        processes[i].wt=current_time;
        current_time+=processes[i].bt;
        processes[i].tat=processes[i].wt+processes[i].bt;
    }
    int total_tat=0;
    int total_wt=0;
    for(int i=0;i<n;i++){
        total_tat+=processes[i].tat;
        total_wt+=processes[i].wt;
    }
    printf("Process\tBurst time\tPriority\tWaiting Time\tTurn around time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",processes[i].process_id,processes[i].bt,processes[i].pt, processes[i].wt,processes[i].tat);
    }
    printf("Average waiting time : %f\n", (float)total_wt/n);
    printf("Average turn around time : %f",(float)total_tat/n);
    
    return 0;
}
