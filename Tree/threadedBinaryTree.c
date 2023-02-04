#include<stdio.h>
#include<stdlib.h>
typedef struct ThreadedBinaryTree{
  struct ThreadedBinaryTree* left;
  int LTag,RTag,data;  
  struct ThreadedBinaryTree* right;  
}tt;

tt* inorderSuccessor(tt* ptr){
    if(ptr->RTag==0){
        return ptr->right;
    }
    else{
        tt* position=ptr->right;
        while(position->LTag==1){
            position=position->left;
        }
        return position;
    }
}
void inorderTraversal(tt* root){
    while(root->LTag!=0){
        root=root->left;
    }
    while(root->right!=root){
        printf("%d ",root->data);
        root=inorderSuccessor(root);
    }
}
tt* preOrderSuccessor(tt* ptr){
    if(ptr->right==ptr)return ptr;
    if(ptr->LTag==1)return ptr->left;
    else{
        while(ptr->RTag!=1){
            ptr=ptr->right;
        }
        return ptr->right;
    }
}
void preOrderTraversal(tt* root){
    if(root->right==root){
        if(root->LTag==1){
            root=root->left;
        }
        else{
            return;
        }
    }
    while(root->right!=root){
        printf("%d ",root->data);
        root=preOrderSuccessor(root);
    }
}

tt* insertionOfRightNode(tt* P ,tt* Q){
    if(P->right==P)return P;
    Q->RTag=P->RTag;
    Q->LTag=0;
    Q->right=P->right;
    P->right=Q;
    Q->left=P;
    P->RTag=1;
    if(Q->RTag==1){
        tt* temp = Q->right;
        while(temp->LTag!=0){
            temp=temp->left;
        }
    }
    return P;
}
int main(){
    tt* root=(tt*)malloc(sizeof(tt));
    tt* dummy=(tt*)malloc(sizeof(tt));
    dummy->left=root;
    dummy->right=dummy;
    dummy->LTag=1;
    dummy->RTag=1;
    root->data=1;
    root->LTag=1;
    root->RTag=1;
    root->left=(tt*)malloc(sizeof(tt));
    root->left->data=5;
    root->left->LTag=1;
    root->left->RTag=0;
    root->left->right=root;
    root->left->left=(tt*)malloc(sizeof(tt));
    root->left->left->data=2;
    root->left->left->LTag=0;
    root->left->left->RTag=0;
    root->left->left->right=root->left;
    root->left->left->left=dummy;
    root->right=(tt*)malloc(sizeof(tt));
    root->right->data=11;
    root->right->LTag=1;
    root->right->RTag=1;
    root->right->left=(tt*)malloc(sizeof(tt));
    root->right->left->data=16;
    root->right->left->LTag=0;
    root->right->left->left=root;
    root->right->left->RTag=0;
    root->right->left->right=root->right;
    root->right->right=(tt*)malloc(sizeof(tt));
    root->right->right->data=31;
    root->right->right->LTag=0;
    root->right->right->left=root->right;
    root->right->right->RTag=0;
    root->right->right->right=dummy;
    // printf("%d",(inorderSuccessor(root->left->left))->data);
    // printf("%d\n",(preOrderSuccessor(root))->data);
    // inorderTraversal(root);
    // printf("\n");
    // preOrderTraversal(root);
    tt* Q=(tt*)malloc(sizeof(tt));
    Q->data=32;
    insertionOfRightNode(root,Q);
    inorderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
}