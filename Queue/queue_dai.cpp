// Dynamic Circular array Implementation
#include<iostream>
using namespace std;
typedef struct DynamicArrayQueue{
    int front,rear;
    int capacity;
    int *arr;
}daq;
daq* createDynQueue(){
    daq* Q = (daq*)malloc(sizeof(daq));
    if(!Q)return NULL;
    Q->capacity=1;
    Q->front=Q->rear=-1;
    Q->arr=(int *)malloc(Q->capacity*sizeof(int));
    if(!(Q->arr))return NULL;
    return Q;
}
bool isEmptyQueue(daq* Q){
    if(Q->front==-1){
        return true;
    }
    return false;
}
bool isQueueFull(daq* Q){
    if((Q->rear+1)%Q->capacity == Q->front){
        return true;
    }
    return false;
}
int QueueSize(daq* Q){
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}
void resizeQueue(daq *Q){
    int size = Q->capacity;
    Q->capacity=Q->capacity*2;
    Q->arr=(int *)realloc(Q->arr,Q->capacity*sizeof(int));
    if(!(Q->arr)){
        cout<<"Memory Error"<<endl;
        return;
    }
    if(Q->front>Q->rear){
        for(int i=0;i<Q->front;i++){
            Q->arr[i+size]=Q->arr[i];
        }
        Q->rear=Q->rear + size;
    }
}
void EnQueue(daq* Q,int data){
    if(isQueueFull(Q)){
        resizeQueue(Q);
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear]=data;
    if(Q->front==-1){
        Q->front=Q->rear;
    }
}
int DeQueue(daq* Q){
    int data=0;
    if(isEmptyQueue(Q)){
        cout<<"Queue is empty"<<endl;
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
void DeleteQueue(daq* Q){
    if(Q){
        if(Q->arr){
            free(Q->arr);
        }
        free(Q);
    }
}
int main(){
    daq* Q = createDynQueue();
    cout<<"Is Queue Empty "<<isEmptyQueue(Q)<<endl<<"Is Queue Full "<<isQueueFull(Q)<<endl<<"Size of the Queue is "<<QueueSize(Q)<<endl;
    for(int i=0;i<8;i++){
        EnQueue(Q,i+1);
    }
    cout<<"Is Queue Empty "<<isEmptyQueue(Q)<<endl<<"Is Queue Full "<<isQueueFull(Q)<<endl<<"Size of the Queue is "<<QueueSize(Q)<<endl;
    for(int i=0;i<8;i++){
        cout<<DeQueue(Q)<<endl;
    }
    cout<<"Is Queue Empty "<<isEmptyQueue(Q)<<endl<<"Is Queue Full "<<isQueueFull(Q)<<endl<<"Size of the Queue is "<<QueueSize(Q)<<endl;
    DeleteQueue(Q);
    return 0;
}