#include<stdio.h>
#include<stdlib.h>
typedef struct element{
    int data;
    int priority;
}element;
typedef struct PriorityQueue{
    int front;
    int rear;
    int capacity;
    element* arr;
}PQ;
PQ* createPQ(){
    PQ* q=(PQ*)malloc(sizeof(PQ));
    if(!q){
        printf("Memory Err\n");
        return NULL;
    }
    q->capacity=MAX_CAPACITY;
    q->front=q->rear=-1;
    q->arr=(element*)malloc(sizeof(element)*q->capacity);
    if(!q->arr){
        printf("Memory Err\n");
        return NULL;
    }
    return q;
}
int IsPriorityQueueFull(PQ* Q){
    if((Q->rear+1)%Q->capacity==Q->front)return 1;
    return 0;
}
int IsPriorityQueueEmpty(PQ* Q){
    if(Q->front==-1)return 1;
    return 0;
}
void resize(PQ* Q){
    int size = Q->capacity;
    Q->capacity*=2;
    Q->arr=(element*)realloc(Q->arr,sizeof(element)*Q->capacity);
    if(Q->front>Q->rear){
        for(int i=0;i<Q->front;i++){
            Q->arr[i+size]=Q->arr[i];
        }
        Q->rear+=size;
    }
}
void PQEnqueue(PQ* Q,int data,int priority){
    if(IsPriorityQueueFull(Q)){
        resize(Q);
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear].data=data;
    Q->arr[Q->rear].priority=priority;
    if(Q->front==-1){
        Q->front=Q->rear;
    }
}
element *find(PQ* Q,int data){
    for(int i=Q->front;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
        if(Q->arr[i].data=data){
            return &Q->arr[i];
        }
    }
    return NULL;
}
int peek(PQ* Q){
    if(IsPriorityQueueEmpty(Q)){
        printf("No Element in Queue");
        return -1;
    }
    int min=INT_MAX;
    int index=-1;
    for(int i=Q->front;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
        if(Q->arr[i].priority<min){
            min=Q->arr[i].priority;
            index=i;
        }
    }
    return index;
}
int DequeuePQ(PQ* Q){
    if(IsPriorityQueueEmpty(Q)){
        printf("No Element in Queue");
        return -1;
    }
    int index = peek(Q);
    int data = Q->arr[index].data;
    if(Q->front == Q->rear){
        Q->front = Q->rear =-1;
    }
    else{
        for(int i=index;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
            Q->arr[i]=Q->arr[(i+1)%Q->capacity];
        }
        Q->rear=(Q->rear-1)%Q->capacity;
    }
    return data;
}