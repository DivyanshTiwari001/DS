#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define MAX_CAPACITY 1
typedef struct element{
    char* data;
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
void PQEnqueue(PQ* Q,char* data,int priority){
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
element *find(PQ* Q,char* data){
    for(int i=Q->front;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
        if(Q->arr[i].data==data){
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
    int index=0,min=Q->arr[Q->front].priority;
    if(Q->front==Q->rear){
        index=0;
    }
    for(int i=(Q->front+1)%Q->capacity;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
        if(Q->arr[i].priority<min){
            min=Q->arr[i].priority;
            index=i;
        }
    }
    return index;
}
char* DequeuePQ(PQ* Q){
    if(IsPriorityQueueEmpty(Q)){
        printf("No Element in Queue");
        return NULL;
    }
    int index = peek(Q);
    char* str = Q->arr[index].data;
    if(Q->front == Q->rear){
        Q->front = Q->rear =-1;
    }
    else{
        for(int i=index;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
            Q->arr[i]=Q->arr[(i+1)%Q->capacity];
        }
        Q->rear=(Q->rear-1)%Q->capacity;
    }
    return str;
}
void DeletePQ(PQ* Q){
    if(Q){
        if(Q->arr){
            if(Q->front==Q->rear){
                free(Q->arr[Q->front].data);
            }
            else{
                for(int i=Q->front;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
                    free(Q->arr[i].data);
                }
            }
            free(Q->arr);
        }
        free(Q);
    }
}
int main(){
    PQ* Q = createPQ();
    printf("Welcome to the process scheduling application!\n");
    int n=-1,p=0;
    char* data;
    while(n!=0){
        printf("\nEnter Task: 1\n");
        printf("Termination: 0\n");
        scanf(" %d",&n);
        switch(n){
            case 1:
                printf("Enter the task: ");
                data=(char *)malloc(sizeof(char)*100);
                scanf(" %[^\n]%*c",data);
                printf("Enter the priority: ");
                scanf(" %d",&p);
                PQEnqueue(Q,data,p);
                break;
            case 0:
                printf("Are you sure you want to exit[y/n]");
                char c;
                scanf(" %c",&c);
                if(c=='n'){
                    n=-1;
                }
                break;
        }
    }
    printf("\nExecuting Scheduled Tasks...\n");
    while(Q->front!=-1){
       printf("%s\n",DequeuePQ(Q));
    }
    printf("\nThanks for using this application");
    DeletePQ(Q);
}