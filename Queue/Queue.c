#include<stdio.h>
#include<stdlib.h>
#define MAX_CAPACITY 1
typedef struct Queue{
    int front,rear,capacity;
    int* arr;
}Queue;
Queue* createQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(!Q){
        printf("Memory Err\n");
        return NULL;
    }
    Q->front=Q->rear=-1;
    Q->capacity=MAX_CAPACITY;
    Q->arr=(int *)malloc(sizeof(int)*Q->capacity);
    if(!Q->arr){
        printf("Memory Err\n");
        return NULL;
    }
    return Q;
}
int IsQueueEmpty(Queue* Q){
    if(Q->front==-1)return 1;
    else return 0;
}
int IsQueueFull(Queue* Q){
    if((Q->rear+1)%Q->capacity==Q->front)return 1;
    else return 0;
}
int QueueSize(Queue* Q){
    return (Q->capacity-Q->front+Q->rear+1)%Q->capacity;
}
void resize(Queue* Q){
    int size = Q->capacity;
    Q->capacity*=2;
    Q->arr=(int *)realloc(Q->arr,Q->capacity*sizeof(int));
    if(!Q->arr){
        printf("Memory Err");
        return;
    }
    if(Q->front>Q->rear){
        for(int i=0;i<Q->front;i++){
            Q->arr[i+size]=Q->arr[i];
        }
        Q->rear+=size;
    }
}
void EnQueue(Queue* Q,int val){
    if(IsQueueFull(Q)){
        resize(Q);
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear]=val;
    if(Q->front==-1){
        Q->front=Q->rear;
    }  
}
int DeQueue(Queue* Q){
    if(IsQueueEmpty(Q)){
        printf("Err:Queue UnderFlow\n");
        return -1;
    }
    int temp=Q->front;
    if(Q->front==Q->rear){
        Q->front=Q->rear=-1;
    }
    else{
        Q->front=(Q->front+1)%Q->capacity;
    }
    return Q->arr[temp];
}
void DeleteQueue(Queue* Q){
    if(Q){
        if(Q->arr)free(Q->arr);
        free(Q);
    }
}
int main(){
 Queue* Q = createQueue();
 int n=-1,data;
 printf("Welcome to the Queue management program\n");
    while(n!=0){
        printf("\nEnQueue element:1\n");
        printf("DeQueue element:2\n");
        printf("Exit : 0\n");
        scanf("%d",&n);
        switch(n){
            case 1:
               printf("Enter the data: ");
               scanf("%d",&data);
               EnQueue(Q,data);
               break; 
            case 2:
                printf("Dequeuing Front element ...\n");
                int temp=DeQueue(Q);
                if(temp!=-1){
                    printf("Element: %d\n",temp);
                    printf("Dequeued element successfully!\n");
                }
                break;
        }
    }
    printf("\nThanks for using application");
    DeleteQueue(Q);
    return 0;
}