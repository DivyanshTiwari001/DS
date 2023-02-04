#include<stdio.h>
#include<stdlib.h>
#include<limits.h> 
typedef struct Stack{
   int data;
   struct Stack* next; 
}Stack;
struct Stack* createStack(){
    return NULL;
}
void push(struct Stack **top,int data){
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    if(!temp)return;
    temp->data=data;
    temp->next=*top;
    *top=temp;
}
int isEmptyStack(struct Stack *top){
    return top==NULL;
}
int pop(struct Stack **top){
    if(!top){
        return -1;
    }
    struct Stack* temp =*top;
    *top=temp->next;
    int value=temp->data;
    free(temp);
    return value;
}
int Top(struct Stack* top){
    if(!top){
        return INT_MIN;
    }
    return top->data;
}
void DeleteStack(struct Stack* top){
    struct Stack* temp=NULL,*current=top;
    while(current){
        temp=current;
        current=current->next;
        free(temp);
    }
}

