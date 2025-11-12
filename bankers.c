#include <stdio.h>

int main(void){
        int n,m;
        printf("\nEnter no of processes:");
        scanf("%d",&n);
        printf("\nEnter no of resources:");
        scanf("%d",&m);

        int alloc[10][10],max[10][10],need[10][10],avail[10],safeseq[10],finish[10],index=0;

        printf("\nEnter Allocation Matrix:");
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        printf("Enter value:");
                        scanf("%d",&alloc[i][j]);
                }
        }

        printf("\nEnter Max Matrix:");
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        printf("Enter Value:");
                        scanf("%d",&max[i][j]);
                }
        }

        printf("\nEnter Available Array:");
        for(int j=0;j<m;j++){
                printf("Enter Value:");
                scanf("%d",&avail[j]);
        }

        //Calculating need
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        need[i][j] = max[i][j] - alloc[i][j];
                }
        }

        for(int i=0;i<n;i++){
                finish[i]=0;
        }

        //Safety
        for(int count =0 ;count<n;count++){
                for(int i=0;i<n;i++){
                        if(finish[i]==0){
                                int canExecute = 1;
                                for(int j=0;j<m;j++){
                                        if(need[i][j] > avail[j]){
                                                canExecute = 0;
                                                break;
                                        }
                                }
                                if(canExecute){
                                        for(int y=0;y<m;y++){
                                                avail[y] += alloc[i][y];
                                        }
                                finish[i] = 1;
                                safeseq[index++] = i;
                                }
                        }
                }
        }

        //display
        int safe=1;
        for(int i=0;i<n;i++){
                if(finish[i]==0){
                        safe=0;
                        break;
                }
        }
        if(safe){
                printf("\nSystem in safe state\nSafe Seq:\n");
                for(int x=0;x<index;x++){
                        printf("%d\t",safeseq[x]);
                }
        }else{
                printf("Sequence not in safe state");
        }
}


