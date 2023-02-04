// Simple Circular array implementation
#include<iostream>
using namespace std;

typedef struct ArrayQueue{
        int front,rear;
        int capacity;
        int *arr;
}aq;
aq* Queue(int size){
    aq* Q = (aq*)malloc(sizeof(aq));
    if(!Q){
        return NULL;
    }
        Q->capacity=size;
        Q->front=Q->rear=-1;
        Q->arr = (int *)malloc(sizeof(int)*Q->capacity);
        if(!Q->arr){
            return NULL;
    }
    return Q;
}
bool isQueueEmpty(aq* Q){
    if(Q->front==-1){
        return true;
    }
    return false;
}
bool isQueueFull(aq* Q){
    if((Q->rear+1)%Q->capacity == Q->front){
        return true;
    }
    return false;
}
int queueSize(aq* Q){
    return ((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}
void Enqueue(aq* Q,int data){
    if(isQueueFull(Q)){
        cout<<"Queue is Full"<<endl;
        return;
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear]=data;
    if(Q->front==-1){
        Q->front=Q->rear;
    }
}
int Deque(aq* Q){
    int data=0;
    if(isQueueEmpty(Q)){
        cout<<"Q is empty"<<endl;
        return 0;
    }
    data=Q->arr[Q->front];
    if(Q->front==Q->rear){
        Q->front=Q->rear=-1;
    }
    else{
         Q->front=(Q->front+1)%Q->capacity;
    }
    return data;
}
void DeleteQueue(aq* Q){
    if(Q){
        if(Q->arr){
            free(Q->arr);
        }
        free(Q);
    }
}
int main(){
    aq* Q = Queue(8);
    cout<<"Is Queue Empty "<<isQueueEmpty(Q)<<endl;
    cout<<"Is Queue full "<<isQueueFull(Q)<<endl<<"Size of the Queue is "<<queueSize(Q)<<endl;
    for(int i=0;i<7;i++){
        Enqueue(Q,i+1);
    }
    cout<<"Is Queue Empty "<<isQueueEmpty(Q)<<endl;
    cout<<"Is Queue full "<<isQueueFull(Q)<<endl<<"Size of the Queue is "<<queueSize(Q)<<endl;
    for(int i=0;i<7;i++){
        cout<<Deque(Q)<<endl;
    }
    cout<<"Is Queue Empty "<<isQueueEmpty(Q)<<endl;
    cout<<"Is Queue full "<<isQueueFull(Q)<<endl<<"Size of the Queue is "<<queueSize(Q)<<endl;
    DeleteQueue(Q);
    return 0;
}