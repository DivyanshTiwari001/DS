// Linked List implementation
#include<iostream>
using namespace std;
typedef struct ListNode{
    int data;
    struct ListNode* next;
}ln;
typedef struct Queue{
    ln* front;
    ln* rear;  
}qu;
qu* createQueue(){
    qu* Q = (qu*)malloc(sizeof(qu));
    if(!Q) return NULL;
    Q->front=Q->rear=NULL;
    return Q;
} 
bool isQueueEmpty(qu* Q){
    if(Q->front==NULL){
        return true;
    }
    return false;
}
void Enqueue(qu* Q,int value){
        ln* newNode=(ln*)malloc(sizeof(ln));
        if(!newNode){
            printf("Memory Err");
            return;
        }
        newNode->data=value;
        newNode->next=NULL;
        if(Q->rear)Q->rear->next=newNode;
        Q->rear=newNode;
        if(Q->front==NULL){
            Q->front=Q->rear;
        }
}
int Dequeue(qu* Q){
    if(isQueueEmpty(Q)){
        printf("Queue is Empty");
        return -1;
    }
    ln* temp=Q->front;
    int value = temp->data;
    Q->front=Q->front->next;
    free(temp);
    return value;
}
void Delete(qu* Q){
    if(Q){
        ln* temp=NULL;
        while(Q->front!=NULL){
            temp=Q->front;
            Q->front=Q->front->next;
            free(temp);
        }
        free(Q);
    }
}
