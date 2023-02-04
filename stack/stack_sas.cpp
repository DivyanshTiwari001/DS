#include<iostream>
#define MAX_CAPACITY 10
using namespace std;
typedef struct ArrayStack{
    int top;
    int capacity;
    int *arr;
}as;
as * createStack(){
    as* s=(as*)malloc(sizeof(as));
    if(!s)return NULL;
    s->capacity=MAX_CAPACITY;     
    s->top=-1;
    s->arr=(int*)malloc(s->capacity*sizeof(int));
    if(!s->arr){
        return NULL;
    }
    return s;
}
int isEmpty(as* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isFull(as* s){
    if(s->top==s->capacity-1){
        return 1;
    }
    return 0;
}
void push(as *s,int value){
    if(isFull(s)){
        cout<<"ERR:Stack Overflow"<<endl;
        return;
    }
    s->arr[++(s->top)]=value;
}
int pop(as* s){
    if(isEmpty(s)){
        cout<<"ERR:Stack Underflow"<<endl;
        return -1;
    }
    return (s->arr[s->top--]);
}
int Top(as* s){
    return(s->arr[s->top]);
}
int size(as* s){
    return(s->top+1);
}
void deleteStack(as* s){
    if(s)
        if(s->arr)
            free(s->arr);
        free(s);
}
int main(){
    as* s=createStack();
    // cout<<"IS EMPTY "<<isEmpty(s);
    for(int i=0;i<5;i++){
        push(s,i+1);
    }
    // cout<<"IS FULL "<<isFull(s);
    cout<<s->top<<endl;
    for(int i=0;i<=s->top;i++){
        cout<<s->arr[i]<<endl;
    }
    // cout<<"Deleted Element "<<pop(s)<<endl;
    cout<<"Top entry "<<Top(s)<<endl<<"Size of stack "<<size(s)<<endl;
    // for(int i=0;i<=s->top;i++){
    //     cout<<s->arr[i]<<endl;
    // }
    deleteStack(s);
    return 0;
}