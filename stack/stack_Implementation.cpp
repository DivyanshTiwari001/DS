#include<iostream>
#include<string.h>
#define MAX_CAPACITY 1
using namespace std;
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
        cout<<"ERR:Stack Underflow"<<endl;
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
int checkBalancedParenthesis(char* str){
     das* s = createStack();
     for(int i=0;i<strlen(str);i++){
        if(str[i]=='('){
            push(s,str[i]);
        }
        else if(!empty(s) && str[i]==')'){
            pop(s);
        }
        else{
            return 0;
        }
     }
   return (empty(s));
}
int palindrome(char* str){
    int i=0;
    das* s = createStack();
    while(str[i]!='X'){
        push(s,str[i++]);
    }
    i++;
    while(i<str.length()){
        if(str[i]==Top(s)){
            pop(s);
            i++;
        }
        else{
            return 0;
        }
    }
    return empty(s);
}
string postfixConvertor(string str){
       str=str+')';
       string res;
       das* s=createStack();
       push(s,'(');
       for(char i:str){
            switch(i){
                case '*':
                case '/':
                while(Top(s)!='(' && Top(s)!='+' && Top(s)!='-'){
                        res=res+pop(s);
                }
                push(s,i);
                break;
                case '+':
                case '-':
                while(Top(s)!='('){
                        res=res+pop(s);
                }
                push(s,i);
                break;
                case '(':
                   push(s,i);
                   break;
                case ')':
                  while(Top(s)!='('){
                    res=res+pop(s);
                  }
                  pop(s);
                break;
                default:
                    res+=i;
            }
       }
    return res;
}
int postfix(char* str){
    das* s=createStack();
    int a,b,data;
    for(int i=0;i<strlen(str);i++){
       switch(str[i]){
        case '*':
        a = pop(s);
        b = pop(s);
        data=a*b;
        push(s,data);
        break;
        case '/':
        a =pop(s);
        b = pop(s);
        data=b/a;
        push(s,data);
        break;
        case '+':
        a = pop(s);
        b = pop(s);
        data=a+b;
        push(s,data);
        break;
        case '-':
         a = pop(s);
        b = pop(s);
        data=b-a;
        push(s,data);
        break;
        default:
          push(s,str[i]-48);
          break;
    }
}
  data = pop(s);
  return data;
}
int main(){
   char str[100];
   printf("Enter the postfix expression to be evaluated\n");
   scanf("%s",str);
//    printf("Value of expression is: %d",postfix(str));
printf("%d ",checkBalancedParenthesis(str));
   return 0;
}