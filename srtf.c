#include <stdio.h>

int main(void){
        int n;
        printf("Enter total number of processes:");
        scanf("%d",&n);

        int p[n];
        int at[n];
        int bt[n];
        int rt[n];
        int ct[n];
        int tat[n];
        int wt[n];

        int time=0,completed=0;
        int smallest;
        for(int i=0;i<n;i++){
                printf("\nFOR PROCESS %d",i);
                p[i] = i+1;
                printf("\nEnter Arrival time:");
                scanf("%d",&at[i]);
                printf("\nEnter Burst time:");
                scanf("%d",&bt[i]);
                rt[i] = bt[i];
        }

        while(completed!=n){ //till all processes complete
                int smallest = -1;
                int min_rt = 999999;
        //to find nexrt shortest rt prcoess
                for(int i=0;i<n;i++){
                        if(at[i]<=time && rt[i]>0 && rt[i]<min_rt){
                                smallest = i;
                                min_rt = rt[i];
                        }
                }
                // if no process
                if(smallest==-1){
                        time++;
                        continue;
                }
                //otherwise
                rt[smallest]--;
                time++;
                //check if process complete;
                if(rt[smallest]==0){
                        completed++;
                        ct[smallest] = time;
                        tat[smallest] = ct[smallest] - at[smallest];
                        wt[smallest] = tat[smallest] - bt[smallest];
                }
        }

        int sum_tat=0,sum_wt = 0;
        for(int x=0;x<n;x++){
                sum_tat += tat[x];
                sum_wt += wt[x];
        }

        printf("P\tAT\tBT\tCT\tTAT\tWT");
        for(int i=0;i<n;i++){
                printf("\n%d\t%d\t%d\t%d\t%d\t%d\t",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
}
