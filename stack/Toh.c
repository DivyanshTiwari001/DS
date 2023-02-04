// using two recursion
#include"stack.h"
#include<math.h>
void toh(int n,char s,char a,char d){
    if(n==0){
        return;
    }
    toh(n-1,s,d,a);
    printf("%d disk from %c to %c\n",n,s,d);
    toh(n-1,a,s,d);
}

// Using No recursion
void toh1(int n,char s,char a,char d){
     Stack* src =createStack();
     Stack* aux =createStack();
     Stack* des =createStack();
     for(int i=n;i>0;i--){
        push(&src,i);
     }
     char A = s;
     char B = a;
     char C = d;
    if(n%2==0){
        B = d;
        C = a;
    }
     for(int i=1;i<pow(2,n);i++){
        if(i%3==1){
            if(isEmptyStack(des) || (!isEmptyStack(src) && Top(des)>Top(src))){
                push(&des,pop(&src));
                printf("%d disk from %c to %c\n",Top(des),A,C);
            }
            else{
                push(&src,pop(&des));
                printf("%d disk from %c to %c\n",Top(src),C,A);
            }
        }
        if(i%3==2){
            if(isEmptyStack(aux) ||(!isEmptyStack(src) && Top(aux)>Top(src))){
                push(&aux,pop(&src));
                printf("%d disk from %c to %c\n",Top(aux),A,B);
            }
            else{
                push(&src,pop(&aux));
                printf("%d disk from %c to %c\n",Top(src),B,A);
            }
        }
        if(i%3==0){
            if(isEmptyStack(des) ||(!isEmptyStack(aux) && Top(des)>Top(aux))){
                push(&des,pop(&aux));
                printf("%d disk from %c to %c\n",Top(des),B,C);
            }
            else{
                push(&aux,pop(&des));
                printf("%d disk from %c to %c\n",Top(aux),C,B);
            }
        }
     }
}
// using one recursion
void toh2(int n,char s,char a,char d){
    if(n==0){
        return;
    }
    toh1(n-1,s,d,a);
    printf("%d disk from %c to %c\n",n,s,d);
    toh2(n-1,a,s,d);
}
int main(){
    int n;
    printf("Enter the number of disk: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
    printf("\nUsing Iteration\n");
    toh1(n,'A','B','C');
    return 0;
}