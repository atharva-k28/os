#include <stdio.h>
#include <limits.h>  // Added for INT_MAX

int main(void){
    int frameCount=0,pageCount=0;
    printf("\nEnter number of frames:");
    scanf("%d",&frameCount);
    printf("\nEnter number of Pages:");
    scanf("%d",&pageCount);

    int frames[20],pages[20],last_time[20];
    int currentTime=0,pageFaults=0;

    for(int i=0;i<frameCount;i++){
        frames[i] = -1;
        last_time[i] = -1;   // initialize both here for simplicity
    }

    for(int i=0;i<pageCount;i++){
        printf("\nEnter Page:");
        scanf("%d",&pages[i]);
    }

    printf("Page\tFrames");

    for(int i=0;i<pageCount;i++){
        int page = pages[i];
        int found = 0;  // initialize properly
        currentTime++;  // time passes for every page access

        // Check if page already exists
        for(int x=0;x<frameCount;x++){
            if(frames[x]==page){
                found = 1;
                last_time[x] = currentTime;   // update time for that frame
                printf("\n%d\tNo Page Fault",page);
                break;
            }
        }

        if(!found){   // moved outside of previous loop
            int placed=0;

            // try to put page in empty frame
            for(int x=0;x<frameCount;x++){
                if(frames[x]==-1){
                    frames[x] = page;
                    last_time[x] = currentTime;
                    placed=1;
                    pageFaults++;
                    printf("\n%d\t",page);
                    for(int y=0;y<frameCount;y++){
                        if(frames[y]==-1)
                            printf("- ");
                        else
                            printf("%d ",frames[y]);
                    }
                    break;
                }
            }

            // if all frames are full → replace LRU
            if(!placed){
                int lru_index = 0;
                int min_time = INT_MAX;
                for(int x=0;x<frameCount;x++){
                    if(last_time[x] < min_time){
                        min_time = last_time[x];
                        lru_index = x;
                    }
                }
                frames[lru_index] = page;
                last_time[lru_index] = currentTime;
                pageFaults++;
                printf("\n%d\t",page);
                for(int y=0;y<frameCount;y++){
                    if(frames[y]==-1)
                        printf("- ");
                    else
                        printf("%d ",frames[y]);
                }
            }
        }
    }

    printf("\n\nTotal Page Faults = %d\n",pageFaults);
}
