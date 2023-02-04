#include<stdio.h>
#include<stdlib.h>
#include"library.h"
typedef struct AvlTreeNode{
    int info;
    int balf;
    struct AvlTreeNode *left,*right,*parent;
}node;
node* search(node* root,int val){
    if(root==NULL || root->info==val)return root;
    else if(root->info<val)return search(root->right,val);
    else if(root->info>val)return search(root->left,val);
}
node* findMax(node* root){
    if(root->right==NULL || root==NULL)return root;
     else return findMax(root->right);
}
void rightRotation(node *ptr,node** root){
    // rotation
    node *temp=ptr->left;
    ptr->left=temp->right;
    temp->right=ptr;

    //updating ptr's parent node pointer
    if(ptr->parent==NULL){
        *root=temp;
    }
    else if(ptr->parent->left==ptr)ptr->parent->left=temp;
    else ptr->parent->right=temp;

    // updating ptr,temp,temp->right parent pointer
    temp->parent=ptr->parent;
    ptr->parent=temp;
    if(ptr->left!=NULL)
        ptr->left->parent=ptr;
}
void leftRotation(node *ptr,node** root){
    // rotation
    node *temp=ptr->right;
    ptr->right=temp->left;
    temp->left=ptr;

    //updating ptr's parent node pointer
    if(ptr->parent==NULL){
        *root=temp;
    }
    else if(ptr->parent->left==ptr)ptr->parent->left=temp;
    else ptr->parent->right=temp;
    // updating ptr,temp,temp->right parent pointer
    temp->parent=ptr->parent;
    ptr->parent=temp;
    if(ptr->right!=NULL)
        ptr->right->parent=ptr;
}

void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->info);
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL)return;
    printf("%d ",root->info);
    preorder(root->left);
    preorder(root->right);
}
node* insert(node* root,int data){
    if(root==NULL){
        node* temp = (node*)malloc(sizeof(node));
        if(!temp)return root;
        temp->info=data;
        temp->left=NULL;
        temp->right=NULL;
        temp->balf=0;
        temp->parent=NULL;
        root=temp;
    }
    else if(root->info<data){
        root->right=insert(root->right,data);
        root->right->parent=root;
    }
    else if(root->info>data){
        root->left=insert(root->left,data);
        root->left->parent=root;
    }
    return root;
}
void insertion(node** root,int val){
    *root=insert(*root,val);
    node* ptr = search(*root,val);
    // updating balance factor
    while(ptr->parent!=NULL){
        if(ptr->parent->left==ptr){
            ptr=ptr->parent;
            ptr->balf++;
        }
        else{
           ptr=ptr->parent;
           ptr->balf--; 
        }
        if(abs(ptr->balf)==2)break;
        else if(ptr->balf==0)return;
    }
    if(abs(ptr->balf)==2){
        // llRotataion
        if(ptr->left && ptr->left->info>val){
            ptr->balf=ptr->left->balf=0;
            rightRotation(ptr,root);
        }
        // RRRotation
        else if(ptr->right && ptr->right->info<val){
            ptr->balf=ptr->right->balf=0;
            leftRotation(ptr,root);
        }
        // LRRotation
        else if(ptr->info>val && ptr->left->info<val){
            switch(ptr->left->right->balf){
                case 0:
                ptr->balf=ptr->left->balf=0;
                break;
                case 1:
                ptr->balf=-1;
                ptr->left->balf=0;
                break;
                case -1:
                ptr->balf=0;
                ptr->left->balf=1;
            }
            ptr->left->right->balf=0;
            leftRotation(ptr->left,root);
            rightRotation(ptr,root);
        }
        //RLRotation 
        else if(ptr->right->info>val && ptr->info<val){
            switch(ptr->right->left->balf){
                case 0:
                ptr->balf=ptr->left->balf=0;
                break;
                case 1:
                ptr->balf=0;
                ptr->right->balf=-1;
                break;
                case -1:
                ptr->balf=1;
                ptr->right->balf=0;
            }
            ptr->right->left->balf=0;
            rightRotation(ptr->right,root);
            leftRotation(ptr,root);
        }
    }
    
}
void balancing_of_tree(node** ptr,node** root){
    printf("\nCalled me\n");
    if((*ptr)->balf==-2){
        if((*ptr)->right->balf==0){
            (*ptr)->right->balf=1;
            (*ptr)->balf=1;
            leftRotation(*ptr,root);
        }
        else if((*ptr)->right->balf==-1){
            (*ptr)->balf=0;
            (*ptr)->right->balf=0;
            leftRotation(*ptr,root);
        }
        else if((*ptr)->right->balf==1){
            if((*ptr)->right->left->balf==0){
                (*ptr)->balf=0;
                (*ptr)->right->balf=0;
            }
            else if((*ptr)->right->left->balf==-1){
                (*ptr)->balf=1;
                (*ptr)->right->balf=0;
                (*ptr)->right->left->balf=0;
            }
            else if((*ptr)->right->left->balf==1){
                (*ptr)->balf=0;
                (*ptr)->right->balf=1;
                (*ptr)->right->left->balf=0;
            }
            rightRotation((*ptr)->right,root);
            leftRotation(*ptr,root);
        }
    }
    else if((*ptr)->balf==2){
        if((*ptr)->right->balf==0){
            rightRotation(*ptr,root);
        }
        else if((*ptr)->right->balf==-1){
            leftRotation((*ptr)->left,root);
            rightRotation(*ptr,root);
        }
        else if((*ptr)->right->balf==1){
            rightRotation(*ptr,root);
        }
    }
}
node* delete(node* root,int val){
   

}
int main(){
    node *root=NULL;
    for(int i=0;i<10;i++){
        insertion(&root,i+1);
    }
    inorder(root);
    root=delete(root,3,);
    // root=delete(root,8);
    root=delete(root,2);
    printf("\n");
    preorder(root);
    printf("\n");
    printf("%d",root->balf);
    printf("\n");
    printf("%d",root->right->info);
    printf("\n");
    inorder(root);
}