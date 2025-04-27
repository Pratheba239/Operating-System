#include<stdio.h>
int findturnaroundtime(int process[],int n,int bt[],int tat[],int *totaltat){
    for(int i=0;i<n;i++){
        if(i==0){
            tat[i]=bt[i];
        *totaltat=tat[i]+*totaltat;
        }
        else{
        tat[i]=bt[i]+tat[i-1];
        *totaltat=tat[i]+*totaltat;
    }
    }
    return *totaltat;
}
int findwaitingtime(int process[],int n,int bt[],int tat[],int wt[],int *totalwt){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=tat[i-1];
        *totalwt+=wt[i];
    }
    return *totalwt;
}
int findavgtime(int process[],int n,int bt[]){
    int tat[n],wt[n],totaltat=0,totalwt=0;
    findturnaroundtime(process,n,bt,tat,&totaltat);
    findwaitingtime(process,n,bt,tat,wt,&totalwt);
    printf("Process\tBurst time\tTurn around time\tWaiting time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",process[i],bt[i],tat[i],wt[i]);
    }
    printf("Average turn around time :%f\n",(float)totaltat/n);
    printf("Average waiting time : %f",(float)totalwt/n);
    
}
int main(){
    int n;
    printf("Enter no of process:");
    scanf("%d",&n);
    int process[n];
    int bt[n];
    for(int i=0;i<n;i++){
        printf("Enter process number :");
        scanf("%d",&process[i]);
        printf("Enter burst time of  %d process:",process[i]);
        scanf("%d",&bt[i]);
    }
    findavgtime(process,n,bt);
    return 0;
    
}
