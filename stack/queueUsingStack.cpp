#include<iostream>
using namespace std;
typedef struct Stack{
    int data;
    struct Stack* next;
}s;
s* createStack(){
    return NULL;
}
void push(s** top,int data){
    s* newNode=(s*)malloc(sizeof(s));
    if(!newNode){
        return ;
    }
    newNode->data=data;
    newNode->next=(*top);
    *top=newNode;
}
int pop(s** top){
    if(!top){
        return -1;
    }
    s* temp=(*top);
    *top=(*top)->next;
    int data=temp->data;
    free(temp);
    return data;
}
s* top1=createStack(),*top2=createStack();
void Enqueue(int data){
    push(&top1,data);
}
int dequeue(){
    if(top2==NULL){
        while(top1!=NULL){
            push(&top2,pop(&top1));
        }
    }
    if(top2==NULL){
        return -1;
    }
    return pop(&top2);
}
int main(){
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    cout<<dequeue();
    cout<<dequeue();
    Enqueue(4);    
    cout<<dequeue();
    Enqueue(6);
    cout<<dequeue();
    cout<<dequeue();
}