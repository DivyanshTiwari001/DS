#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int factorial(int n){
    Stack* s = createStack();
    int fact=1;
    while(n>0){
        push(&s,n);
        n--;
    }
    while(!isEmptyStack(s)){
        fact *=pop(&s);
    }
    return fact;
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,factorial(n));
}