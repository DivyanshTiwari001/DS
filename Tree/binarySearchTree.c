#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct binarySearchTree{
    int data;
    struct binarySearchTree* left;
    struct binarySearchTree* right;
}bst;
bst* find(bst* root , int data){
    if(root==NULL)return NULL;
    else if(root->data==data)return root;
    else if(root->data<data)return find(root->right,data);
    else if(root->data>data)return find(root->left,data);
}
bst* findMin(bst* root){
    if(root==NULL || root->left == NULL)return root;
    else return findMin(root->left);
}
bst* findMax(bst* root){
    if(root==NULL || root->right == NULL)return root;
    else return findMax(root->right);
}
bst* insert(bst* root,int data){
    if(root==NULL){
        bst* temp = (bst*)malloc(sizeof(bst));
        if(!temp)return root;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return root;
    }
    else if(root->data<data){
        root->right=insert(root->right,data);
    }
    else if(root->data>data){
        root->left=insert(root->left,data);
    }
    return root;
}
bst* DeleteNode(bst* root, int data){
    if(root==NULL)return NULL;
    else if(root->data<data){
        root->right=DeleteNode(root->right,data);
    }
    else if(root->data>data){
        root->left=DeleteNode(root->left,data);
    }
    else{
        if(root->left!=NULL && root->right!=NULL){
            bst* temp = findMax(root->left);
            root->data=temp->data;
            root->left=DeleteNode(root->left,root->data);
        }
        else{
            bst* temp = root;
            if(root->left==NULL){
                root=root->right;
            }
            else if(root->right==NULL){
                root=root->left;
            }  
            free(temp);
        }
    }
    
    return root;
}
void inorder(bst* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(bst* root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int kthSmallest(bst* root,int k){
    if(root==NULL){
        return k;
    }
    k=kthSmallest(root->left,k)-1;
    if(k==0){
        printf("%d",root->data);
        exit(0);
    }
    kthSmallest(root->right,k);
    return k;
}
int main(){
    bst* root = NULL;
   root=insert(root,10);
   root=insert(root,15);
   root=insert(root,1);
   root=insert(root,40);
   root=insert(root,14);
   root=insert(root,54);
   root=insert(root,40);
   root=insert(root,11);
   root=insert(root,0);
   root=insert(root,5);
   root=insert(root,6);
   inorder(root);
   printf("\n");
   preorder(root);
   printf("\n");
    kthSmallest(root,5);
    return 0;
}