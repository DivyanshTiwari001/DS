#include<stdio.h>
#include<stdlib.h>
#define MAX_CAPACITY 1
typedef struct DynamicArrayStack{
    int top;
    int capacity;
    int *arr;
}das;
das * createStack(){
    das* s=(das*)malloc(sizeof(das));
    if(!s)return NULL;
    s->capacity=MAX_CAPACITY;     
    s->top=-1;
    s->arr=(int*)malloc(s->capacity*sizeof(int));
    if(!s->arr){
        return NULL;
    }
    return s;
}
int isEmpty(das* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isFull(das* s){
    if(s->top==s->capacity-1){
        return 1;
    }
    return 0;
}
void doubleStackSize(das* s){
    s->capacity*=2;
    s->arr=(int *)realloc(s->arr,sizeof(int)*s->capacity);
}
void push(das *s,int value){
    if(isFull(s)){
       doubleStackSize(s);
    }
    s->arr[++(s->top)]=value;
}
int pop(das* s){
    if(isEmpty(s)){
        printf("ERR:Stack Underflow\n");
        return -1;
    }
    return (s->arr[s->top--]);
}
int Top(das* s){
    if(s->top==-1)return -1;
    return(s->arr[s->top]);
}
int size(das* s){
    return(s->top+1);
}
void deleteStack(das* s){
    if(s){
        if(s->arr)
            free(s->arr);
        free(s);
    }
}
int main(){
    das* s = createStack();
    int n=-1,data;
    printf("Welcome to the stack management program\n");
    while(n!=0){
        printf("\nPush element:1\n");
        printf("Pop element:2\n");
        printf("Top element:3\n");
        printf("Exit : 0\n");
        scanf("%d",&n);
        switch(n){
            case 1:
               printf("Enter the data: ");
               scanf("%d",&data);
               push(s,data);
               break; 
            case 2:
                printf("Popping out top element ...\n");
                pop(s);
                break;
            case 3:
                printf("Topmost element: %d\n",Top(s));
                break;
        }
    }
    printf("\nThanks for using application");
    deleteStack(s);
    return 0;
}