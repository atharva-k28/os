#include <stdio.h>

int main(void){
        int n;
        printf("Enter total number of processes:");
        scanf("%d",&n);

        int p[n];
        int at[n];
        int bt[n];
        int ct[n];
        int tat[n];
        int wt[n];

        for(int i=0;i<n;i++){
                printf("\nFOR PROCESS %d",i);
                p[i] = i+1;
                printf("\nEnter Arrival time:");
                scanf("%d",&at[i]);
                printf("\nEnter Burst time:");
                scanf("%d",&bt[i]);
        }
        for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                        if(at[j]>at[j+1]){
                                int temp = p[j];
                                p[j] = p[j+1];
                                p[j+1] = temp;

                                temp = at[j];
                                at[j] = at[j+1];
                                at[j+1] = temp;

                                temp = bt[j];
                                bt[j] = bt[j+1];
                                bt[j+1] = temp;
                        }
                }
        }
        for(int i=0;i<n;i++){
                if(i==0){
                        ct[i] = at[i] + bt[i];
                }else{
                        ct[i] = ct[i-1] > at[i] ? ct[i-1] + bt[i] : at[i] + bt[i];
                }
        }

        int sum_tat=0,sum_wt = 0;
        for(int x=0;x<n;x++){
                tat[x] = ct[x] - at[x];
                sum_tat += tat[x];
                wt[x] = tat[x] - bt[x];
                sum_wt += wt[x];
        }

        printf("P\tAT\tBT\tCT\tTAT\tWT");
        for(int i=0;i<n;i++){
                printf("\n%d\t%d\t%d\t%d\t%d\t%d\t",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
}
