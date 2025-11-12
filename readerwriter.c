#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex,rwrt;
int readcount = 0;
int sharedvar = 99;
pthread_t readers[5],writers[5];

void reader(){
        sem_wait(&mutex);
        readcount++;
        if(readcount == 1){
                sem_wait(&rwrt);
        }
        sem_post(&mutex);
        printf("\nReader is reading sharedvar %d",sharedvar);
        printf("\nReader is done");
        sem_wait(&mutex);
        readcount--;
        if(readcount == 0){
                sem_post(&rwrt);
        }
        sem_post(&mutex);
}

void writer(){
        sem_wait(&rwrt);
        printf("\nWriter is writing");
        sharedvar++;
        printf("\nWriter is done");
        sem_post(&rwrt);
}

int main(void){
        int n;
        printf("\nEnter number of readers and writers:");
        scanf("%d",&n);

        sem_init(&mutex,0,1);
        sem_init(&rwrt,0,1);

        for(int i=0;i<n;i++){
                pthread_create(&writers[i],NULL,(void *)writer,NULL);
                pthread_create(&readers[i],NULL,(void *)reader,NULL);
        }

        for(int i=0;i<n;i++){
                pthread_join(writers[i],NULL);
                pthread_join(readers[i],NULL);
        }
}
