#include <stdio.h>

int main(void){
        int frameCount, pageCount;
        printf("\nEnter no of Frames:");
        scanf("%d",&frameCount);
        printf("\nEnter no of Pages:");
        scanf("%d", &pageCount);

        int frames[20],pages[20];
        for(int i=0;i<frameCount;i++){
                frames[i] = -1;
        }
        for(int i=0;i<pageCount;i++){
                printf("\nEnter Page:");
                scanf("%d",&pages[i]);
        }

        int front = 0,pageFaults=0;
        printf("Page\tFrames");
        for(int i=0;i<pageCount;i++){
                int page = pages[i];
                int found = 0;
                for(int x=0;x<frameCount;x++){
                        if(frames[x]==page){
                                found=1;
                                printf("\n%d\tNo Page Fault",page);
                                break;
                        }
                }
                if(!found){
                        frames[front] = page;
                        front = (front+1)%frameCount;
                        pageFaults++;
                        printf("\n%d\t",page);
                        for(int x=0;x<frameCount;x++){
                                if(frames[x]==-1){
                                        printf("- ");
                                }else{
                                        printf("%d ",frames[x]);
                                }
                        }
                }
        }
}



