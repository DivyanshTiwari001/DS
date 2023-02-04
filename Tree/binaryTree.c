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
void preOrderUsingRecursion(bt* root){
    if(root){
        printf("%d ",root->data);
        preOrderUsingRecursion(root->left);
        preOrderUsingRecursion(root->right);
    }
}
void inOrderUsingRecursion(bt* root){
    if(root){
        inOrderUsingRecursion(root->left);
        printf("%d ",root->data);
        inOrderUsingRecursion(root->right);
    }
}
void postOrderUsingRecursion(bt* root){
    if(root){
        postOrderUsingRecursion(root->left);
        postOrderUsingRecursion(root->right);
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
bt* pop(st** top){
    if(*top==NULL){
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
void preOrderUsingIteration(bt* root){
    st* top = createStack();
    while(1){
        while(root){
            printf("%d ",root->data);
            push(&top,root);
            root=root->left;
        }
        if(!top){
            break;
        }
        root=pop(&top);
        root=root->right;
    }
    DeleteStack(&top);
}
void inOrderUsingIteration(bt* root){
    st* top = createStack();
    while(1){
        while(root){
            push(&top,root);
            root=root->left;
        }
        if(!top){
            break;
        }
        root=pop(&top);
        printf("%d ",root->data);
        root=root->right;
    }
    DeleteStack(&top);
}
void postOrderUsingIteration(bt* root){
    st* top=createStack();
    bt* prev=NULL;
    do{
        while(root!=NULL){
            push(&top,root);
            root=root->left;
        }
        while(root==NULL && top!=NULL){
            root=Top(top);
            if(root->right==NULL || root->right==prev){
                printf("%d ",root->data);
                pop(&top);
                prev=root;
                root=NULL;
            }
            else{
                root=root->right;
            }
        }
    }while(top!=NULL);
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

// SEARCHING IN BINARY TREE
int searchInTree(bt* root,int data){
    if(root){
        if(data==root->data){
            return 1;
        }
        else{
            return searchInTree(root->left,data)||searchInTree(root->right,data);
        }
    }
    return 0;
}
int searchWithoutRecursion(bt* root,int data){
    // using Level traversal
    Queue* q=createQueue();
    EnQueue(q,root);
    while(!IsQueueEmpty(q)){
        bt* temp=DeQueue(q);
        if(data==temp->data){
            return 1;
        }
        if(temp->left){
            EnQueue(q,temp->left);
        }
        if(temp->right){
            EnQueue(q,temp->right);
        }
    }
    DeleteQueue(q);
    return 0;
}
// INSERTION IN BINARY TREE
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
// Dynamic insertion in the binary tree
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
// Size of a Binary Tree
int sizeofTree(bt* root){
    if(!root){
        return 0;
    }
    return sizeofTree(root->left)+1+sizeofTree(root->right);
}
int sizeofTreeWithoutRecursion(bt* root){
    // using level traversal
    Queue* q=createQueue();
    if(!root){
        return 0; 
    }
    EnQueue(q,root);
    int count=0;
    while(!IsQueueEmpty(q)){
        count++;
        bt* temp=DeQueue(q);
        if(temp->left){
            EnQueue(q,temp->left);
        }
        if(temp->right){
            EnQueue(q,temp->right);
        }
    }
    DeleteQueue(q);
    return count;
}
int findMaxElement(bt* root){
    int maxi=INT_MIN;
    if(root){
        if(maxi<root->data){
            maxi=root->data;
        }
        maxi=max(maxi,findMaxElement(root->left));
        maxi=max(maxi,findMaxElement(root->right));
    }
    return maxi;
}
int maximumWithIteration(bt* root){
    //based on preorder
    st* s=createStack();
    int maxi=INT_MIN;
    do{
        while(root){
            maxi=max(maxi,root->data);
            push(&s,root);
            root=root->left;
        }
        root=pop(&s);
        root=root->right;
    }while(s!=NULL);
    DeleteStack(&s);
    return maxi;
}
int maximumWithLevelTraversal(bt* root){
    Queue* q=createQueue();
    EnQueue(q,root);
    int maxi=INT_MIN;
    while(!IsQueueEmpty(q)){
        bt* temp=DeQueue(q);
        if(maxi<temp->data){
            maxi=temp->data;
        }
        if(temp->left){
            EnQueue(q,temp->left);
        }
        if(temp->right){
            EnQueue(q,temp->right);
        }
    }
    DeleteQueue(q);
    return maxi;
}
// Deleting the tree
void DeleteTree(bt** root){
    if(*root == NULL){
        return;
    }
    else{
        DeleteTree(&((*root)->left));
        DeleteTree(&((*root)->right));
        free(*root);
    }
    
}
// Height of the tree
int heightofTree(bt* root){
    if(root == NULL){
        return -1;
    }
    else{
        return max(heightofTree(root->left),heightofTree(root->right))+1;
    }
}
// Without recursion
int heightIteration(bt* root){
    if(root == NULL){
        return -1;
    }
    Queue* Q = createQueue();
    EnQueue(Q,root);
    EnQueue(Q,NULL);
    int level=-1;
    while(!IsQueueEmpty(Q)){
        root=DeQueue(Q);
        if(root==NULL){
            if(!IsQueueEmpty(Q)){
                EnQueue(Q,NULL);
            }
            level++;
        }
        else{
            if(root->left){
                EnQueue(Q,root->left);
            }
            if(root->left){
                EnQueue(Q,root->left);
            }
        }
    }
    DeleteQueue(Q);
    return level;
}
// leaf Nodes
int leafNode(bt* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return leafNode(root->left)+leafNode(root->right);
}
// Without recursion
int leafNodeIteration(bt* root){
    if(root==NULL){
        return 0;
    }
    Queue* q = createQueue();
    int leaves=0;
    EnQueue(q,root);
    while(!IsQueueEmpty(q)){
        root=DeQueue(q);
        if(root->left==NULL && root->right==NULL){
            leaves++;
        }
        else{
            if(root->left){
                EnQueue(q,root->left);
            }
            if(root->right){
                EnQueue(q,root->right);
            }
        }
    }
    DeleteQueue(q);
    return leaves;
}
// Full Node 
int fullNodes(bt* root){
    if(root==NULL){
        return 0;
    }
    Queue* q = createQueue();
    int fullNode=0;
    EnQueue(q,root);
    while(!IsQueueEmpty(q)){
        root=DeQueue(q);
        if(root->left!=NULL && root->right!=NULL){
            fullNode++;
        }
        if(root->left){
            EnQueue(q,root->left);
        }
        if(root->right){
            EnQueue(q,root->right);
        }
    }
    DeleteQueue(q);
    return fullNode;
}
// Auxilliary Functions
void reverseOrderofLevelTraversal(bt* root){
    if(!root){
        return;
    }
    Queue *q=createQueue();
    st* s=createStack();
    EnQueue(q,root);
    while(!IsQueueEmpty(q)){
        bt* temp=DeQueue(q);
        if(temp->left){
            EnQueue(q,temp->left);
        }
        if(temp->right){
            EnQueue(q,temp->right);
        }
        push(&s,temp);
    }
    DeleteQueue(q);
    while(s!=NULL){
        bt* temp=pop(&s);
        printf("%d ",temp->data);
    }
    DeleteStack(&s);
    return;
}

// Quasi isomorphic tree
int checkQuasiIsomorph(bt* root1,bt* root2){
    if(!root1 && !root2)return 1;
    else if ( (!root1 && root2) || (root1 && !root2)){
        return 0;
    }
    return (checkQuasiIsomorph(root1->left,root2->left)&&checkQuasiIsomorph(root1->right,root2->right)) ||( checkQuasiIsomorph(root1->left,root2->right)&&checkQuasiIsomorph(root1->right,root2->left));
}
void findPrev(bt** root,bt* Node){
    if(*root==NULL)return;
    if((*root)->left==Node){
        (*root)->left=NULL;
        return;
    }
    else if((*root)->right==Node){
        (*root)->right=NULL;
        return;
    }
    findPrev(&((*root)->left),Node);
    findPrev(&((*root)->right),Node); 
}
bt* deleteNode(bt** root, bt* Node){
    if(*root == NULL){
        return NULL;
    }
    Queue *Q = createQueue();
    EnQueue(Q,*root);
    while(!IsQueueEmpty(Q)){
        bt* temp=DeQueue(Q);
        if(temp->left==NULL && temp->right==NULL){
            int a=Node->data;
            Node->data=temp->data;
            temp->data=a;
            DeleteQueue(Q);
            findPrev(root,temp);
            free(temp);
        }
        else{
            if(temp->left)
                EnQueue(Q,temp->left);
            if(temp->right)
                EnQueue(Q,temp->right);
        }
    }
}
// int main(){
// //  bt* root1=createTree();
// //  bt* root2=createTree();
// bt* root1=NULL;
// bt* root2=NULL;
//  for(int i=0;i<10;i++){
//     insertInTree(&root1,i+1);
//  }
//  for(int i=0;i<10;i++){
//     insertInTree(&root2,i+1);
//  }
// preOrderUsingRecursion(root1);
// printf("\n");
// findPrev(&root1,deleteNode(&root1,root1));
// preOrderUsingRecursion(root1);
// // printf("Is root1 is quasi isomorph to root2: %d",checkQuasiIsomorph(root1,root2));
// //  preOrderUsingRecursion(root);
// //  printf("\n");
// //  preOrderUsingIteration(root);
// //  printf("\n");
// //  inOrderUsingRecursion(root);
// //  printf("\n");
// //  inOrderUsingIteration(root);
// //  printf("\n");
// //  postOrderUsingRecursion(root);
// //  printf("\n");
// //  postOrderUsingIteration(root);
// //  printf("\n");
// // levelTraversal(root);
// // printf("\n%d",findMaxElement(root));
// // printf("\n%d",maximumWithIteration(root));
// // printf("\n%d",maximumWithLevelTraversal(root));
// // printf("\nIs 21 present: %d",searchInTree(root,21));
// // printf("\nIs 10 present: %d",searchWithoutRecursion(root,10));
// // printf("\nSize of the binary tree is: %d",sizeofTree(root));
// // printf("\nSize of the binary tree is: %d",sizeofTreeWithoutRecursion(root));
// // printf("\n");
// // reverseOrderofLevelTraversal(root);
// // printf("\nHeight of tree is %d",heightofTree(root));
// // printf("\nHeight of tree is %d",heightIteration(root));
// // printf("\nleaves of tree is %d",leafNode(root));
// // printf("\nleaves of tree is %d",leafNodeIteration(root));
// // printf("\nFullNodes of tree is %d",fullNodes(root));
// // reverseOrderofLevelTraversal(root1);
// DeleteTree(&root1);
// DeleteTree(&root2);
// }
int main(){
    bt* root = NULL;
    for(int i=0;i<10;i++){
        insertInTree(&root,i+1);
    }
    preOrderUsingIteration(root);
}