#include<iostream>
#include<climits>
using namespace std;
struct Stack{
   int data;
   struct Stack* next; 
};
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
    if(isEmptyStack(*top)){
        cout<<"Stack Underflowed"<<endl;
        return -1;
    }
    struct Stack* temp =*top;
    *top=temp->next;
    int value=temp->data;
    free(temp);
    return value;
}
int Top(struct Stack* top){
    if(isEmptyStack(*top)){
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
int size(struct Stack* top){
    struct Stack* temp=top;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    struct Stack* top=createStack();
    for(int i=0;i<10;i++){
        push(&top,i+1);
    }
    cout<<Top(top)<<endl;
    cout<<pop(&top)<<endl;
    cout<<Top(top)<<endl;
    cout<<"IS Empty "<<isEmptyStack(top)<<endl;
    cout<<size(top)<<endl;
    DeleteStack(top);
    return 0;
}