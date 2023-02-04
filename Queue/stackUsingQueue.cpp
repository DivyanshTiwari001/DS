#include<iostream>
#define MAX_SIZE 5
using namespace std;
typedef struct Queue{
    int front,rear;
    int capacity;
    int *arr;
}Queue;

Queue* createQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(!Q){
        return NULL;
    } 
    Q->capacity=MAX_SIZE;
    Q->arr=(int*)malloc(sizeof(int)*Q->capacity);
    if(!Q->arr){
        return NULL;
    }
    Q->front=Q->rear=-1;
    return Q;
}
void Enqueue(Queue* Q,int value){
    if((Q->rear+1)%Q->capacity==Q->front){
        cout<<"Queue is full"<<endl;
        return;
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear]=value;
    if(Q->front==-1){
        Q->front=Q->rear;
    }
}
int dequeue(Queue* Q){
    if(Q->front==-1){
        return -1;
    }
    int data=Q->arr[(Q->front)];
    if(Q->front==Q->rear){
        Q->front=Q->rear=-1;
    }
    else{
        Q->front=(Q->front+1)%Q->capacity;
    }
    return data;
}
Queue *Q=createQueue();
void push(int value){
    Enqueue(Q,value);
}
int size(Queue* Q){
    if((Q->rear+1)%Q->capacity==Q->front)return Q->capacity;
    return (Q->capacity-Q->front+Q->rear+1)%Q->capacity;
}
int pop(){
    int a=size(Q)-1;
    while(a--){
        int temp = dequeue(Q);
        Enqueue(Q,temp);   
    }
    int data=dequeue(Q);
    return data;
}
void reverseStack(){
    Queue *temp=createQueue();
    while(Q->front!=-1){
        Enqueue(temp,pop());
    }
    while(temp->front!=-1){
        push(dequeue(temp));
   }
}
int main(){
    // printf("Hello");
    push(8);
    push(9);
    push(90);
    push(91);
    push(10);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    push(8);
    push(9);
    push(90);
    push(91);
    reverseStack();
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
}