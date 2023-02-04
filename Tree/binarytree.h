#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include"library.h"
typedef struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
}bt;
bt* createTree(){
    int data ;
    printf("Enter the value for the node: ");
    scanf("%d",&data);
    bt* n=(bt*)malloc(sizeof(bt));
    n->data=data;
    n->left=n->right=NULL;
    char choice;
    printf("Do %d node have left child[y/n]: ",n->data);
    scanf(" %c",&choice);
    if(choice=='y'){
        n->left=createTree();
    }
    printf("Do %d node have right child[y/n]: ",n->data);
    scanf(" %c",&choice);
    if(choice=='y'){
        n->right=createTree();
    }
    return n;
}
void preOrder(bt* root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(bt* root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(bt* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

typedef struct Stack{
    bt* data;
    struct Stack* next;
}st;
st* createStack(){
    return NULL;
}
void push(st** top,bt* data){
    st* temp=(st*)malloc(sizeof(st));
    temp->data=data;
    temp->next=*top;
    *top=temp;
}
int isEmptyStack(st* top){
if(top==NULL){
        return 1;
    }
    return 0;
}
bt* pop(st** top){
    if(isEmptyStack(*top)){
        return NULL;
    }
    st* temp =(*top);
    bt* data =temp->data;
    *top=(*top)->next;
    free(temp);
    return data;
}
bt* Top(st* top){
    return top->data;
}
void DeleteStack(st** top){
    st* temp=*top;
    while(*top){
        temp=(*top);
        *top=(*top)->next;
    }
}
typedef struct Queue{
    st* top1;
    st* top2;
}Queue;
Queue* createQueue(){
        Queue* Q=(Queue*)malloc(sizeof(Queue));
        if(!Q){
            return NULL;
        }
        Q->top1=NULL;
        Q->top2=NULL;
        return Q;
}
void EnQueue(Queue* Q,bt* data){
     push(&(Q->top1),data);
}
int IsQueueEmpty(Queue* Q){
    if(Q->top1==NULL && Q->top2==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
bt* DeQueue(Queue* Q){
    if(IsQueueEmpty(Q)){
        return NULL;
    }
    if(Q->top2==NULL){
        while(Q->top1!=NULL){
             push(&(Q->top2),pop(&(Q->top1)));
        }
    }
    return pop(&(Q->top2));
}
void DeleteQueue(Queue* Q){
    if(Q){
        DeleteStack(&(Q->top1));
        DeleteStack(&(Q->top2));
    }
    free(Q);
}
void levelTraversal(bt* root){
        Queue* Q=createQueue();
        if(!root){
            return;
        }
        EnQueue(Q,root);
        while(!IsQueueEmpty(Q)){
            bt* temp=DeQueue(Q);
            printf("%d ",temp->data);
            if(temp->left){
                EnQueue(Q,temp->left);
            }
            if(temp->right){
                EnQueue(Q,temp->right);
            }
        }
        DeleteQueue(Q);
}
void insertInTree(bt** root,int data){
    bt* element=(bt*)malloc(sizeof(bt));
    if(!element){
        printf("Memory Error");
        return;
    }
    element->data=data;
    element->left=NULL;
    element->right=NULL;
    if(*root==NULL){
        *root=element;
        return;
    }
    Queue *q=createQueue();
    EnQueue(q,*root);
    while(!IsQueueEmpty(q)){
        bt* temp=DeQueue(q);
        if(temp->left==NULL){
            temp->left=element;
            DeleteQueue(q);
            return;
        }
        if(temp->right==NULL){
            temp->right=element;
            DeleteQueue(q);
            return;
        }
        EnQueue(q,temp->left);
        EnQueue(q,temp->right);
    }
}