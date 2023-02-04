#include<iostream>
#include<stack>
#define MAX_SIZE 10
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
void reverseQueue(Queue* Q){
    stack<int> s;
    while(Q->front!=-1){
       s.push(dequeue(Q));
    }
    while(s.empty()!=1){
        Enqueue(Q,s.top());
        s.pop();
    }
}
int main(){
    Queue* Q = createQueue();
    Enqueue(Q,4);
    Enqueue(Q,5);
    Enqueue(Q,6);
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    Enqueue(Q,4);
    Enqueue(Q,5);
    Enqueue(Q,6);
    reverseQueue(Q);
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;

    return 0;
}