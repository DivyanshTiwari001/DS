#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_CAPACITY 1
void swap(char *a ,char *b){
    char temp =*a;
    *a=*b;
    *b=temp;
}
typedef struct DynamicArrayStack{
    int top;
    int capacity;
    char *arr;
}das;
das * createStack(){
    das* s=(das*)malloc(sizeof(das));
    if(!s)return NULL;
    s->capacity=MAX_CAPACITY;     
    s->top=-1;
    s->arr=(char*)malloc(s->capacity*sizeof(char));
    if(!s->arr){
        return NULL;
    }
    return s;
}
int empty(das* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int full(das* s){
    if(s->top==s->capacity-1){
        return 1;
    }
    return 0;
}
void doubleStackSize(das* s){
    s->capacity*=2;
    s->arr=(char *)realloc(s->arr,sizeof(char)*s->capacity);
}
void push(das *s,char value){
    if(full(s)){
       doubleStackSize(s);
    }
    s->arr[++(s->top)]=value;
}
char pop(das* s){
    if(empty(s)){
        // cout<<"ERR:Stack Underflow"<<endl;
        return -1;
    }
    return (s->arr[s->top--]);
}
char Top(das* s){
    return(s->arr[s->top]);
}
void deleteStack(das* s){
    if(s)
        if(s->arr)
            free(s->arr);
        free(s);
}
char* postfixConvertor(char* str){
       char c =')';
       strncat(str,&c,1);
       char* res=(char*)malloc(sizeof(char)*100);
       strcpy(res,"");
       das* s=createStack();
       push(s,'(');
       for(int i=0;i<strlen(str);i++){
            switch(str[i]){
                case '*':
                case '/':
                while(Top(s)!='(' && Top(s)!='+' && Top(s)!='-'){
                        c=pop(s);
                        strncat(res,&c,1);
                }
                push(s,str[i]);
                break;
                case '+':
                case '-':
                while(Top(s)!='('){
                        c=pop(s);
                        strncat(res,&c,1);
                }
                push(s,str[i]);
                break;
                case '(':
                   push(s,str[i]);
                   break;
                case ')':
                  while(Top(s)!='('){
                    c=pop(s);
                    strncat(res,&c,1);
                  }
                  pop(s);
                break;
                default:
                    c=str[i];
                    strncat(res,&c,1);
            }
       }
    return res;
}
char* prefix(char* str){
    char c ='(';
    char temp[100]={'\0'};
    strncat(temp,&c,1);
    strcat(temp,str);
    str=temp;
    char* res=(char*)malloc(sizeof(char)*100);
    strcpy(res,"");
    das* s = createStack();
    push(s,')');
    for(int i=strlen(str)-1;i>=0;i--){
        switch(str[i]){
            case '/':
            case '*':
                push(s,str[i]);
                break;
            case '+':
            case '-':
                while(Top(s)!=')' && Top(s)!='+' && Top(s)!='-'){
                    c = pop(s);
                    strncat(res,&c,1);
                }
                push(s,str[i]);
                break;
            case '(':
                while(Top(s)!=')'){
                    c = pop(s);
                    strncat(res,&c,1);
                }
                pop(s);
                break;
            case ')':
                push(s,str[i]);
                break;
            default:
                c=str[i];
                strncat(res,&c,1);
        }
    }
    int n = strlen(res);
    res[n]='\0';
    strcpy(temp,"");
    for(int i=strlen(res)-1;i>=0;i--){
        c = res[i];
        strncat(temp,&c,1);
    }
    strcpy(res,temp);
    return res;
}
int main(){
        char str[100];
        printf("Please Give me infix expression: ");
        scanf("%s",str);
        printf("Postfix expression: %s",postfixConvertor(str));
        printf("\nPrefix expression: %s",prefix(str));
}