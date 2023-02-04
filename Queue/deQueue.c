#include<stdio.h>
#include<stdlib.h>
#define MAX_CAPACITY 1
typedef struct Dequeue{
    int front,rear,capacity;
    int* arr;
}Dequeue;
Dequeue* createDequeue(){
    Dequeue* Q = (Dequeue*)malloc(sizeof(Dequeue));
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
int IsDequeueEmpty(Dequeue* Q){
    if(Q->front==-1)return 1;
    else return 0;
}
int IsDequeueFull(Dequeue* Q){
    if((Q->rear+1)%Q->capacity==Q->front)return 1;
    else return 0;
}
int DequeueSize(Dequeue* Q){
    return (Q->capacity-Q->front+Q->rear+1)%Q->capacity;
}
void resize(Dequeue* Q){
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
void push_back(Dequeue* Q,int val){
    if(IsDequeueFull(Q)){
        resize(Q);
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear]=val;
    if(Q->front==-1){
        Q->front=Q->rear;
    }  
}
void push_front(Dequeue* Q,int val){
    if(IsDequeueFull(Q)){
        resize(Q);
    }
    if(Q->front==-1){
        Q->front=Q->rear=0;
        Q->arr[Q->front]=val;
    }
    else if(Q->front==0){
        Q->front=(Q->capacity-1)%Q->capacity;
        if(Q->front==Q->rear){
            resize(Q);
        }
        Q->arr[Q->front]=val;
    }
    else{
        Q->front=(Q->front-1)%Q->capacity;
        if(Q->front==Q->rear){
            resize(Q);
        }
        Q->arr[Q->front]=val;
    }
}
int pop_front(Dequeue* Q){
    if(IsDequeueEmpty(Q)){
        printf("Err:Dequeue UnderFlow\n");
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
int pop_back(Dequeue* Q){
    if(IsDequeueEmpty(Q)){
        printf("Err:Dequeue UnderFlow\n");
        return -1;
    }
    int temp=Q->rear;
    if(Q->rear==Q->front){
        Q->front=Q->rear=-1;
    }
    else if(Q->rear!=0){
        Q->rear=(Q->rear-1)%Q->capacity;
    }
    else{
        Q->rear=(Q->capacity-1)%Q->capacity;
    }
    return Q->arr[temp];
}
void DeleteDequeue(Dequeue* Q){
    if(Q){
        if(Q->arr)free(Q->arr);
        free(Q);
    }
}
int main(){
    Dequeue* Q = createDequeue();
    printf("These program manages a doubly ended Queue\n");
    int n=-1,data=0;
    while(n!=0){
        printf("\nPush_Front: 1\n");
        printf("Push_Back: 2\n");
        printf("Pop_Front: 3\n");
        printf("Pop_back: 4\n");
        printf("Termination: 0\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                push_front(Q,data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                push_back(Q,data);
                break;
            case 3:
                printf("Popping out from front...\n");
                printf("Data : %d\n",pop_front(Q));
                break;
            case 4:
                printf("Popping out from back...\n");
                printf("Data : %d\n",pop_back(Q));
                break;
        }
    }
    printf("\nThanks for using application");
    DeleteDequeue(Q);
    return 0;
}