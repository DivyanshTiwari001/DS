#include<stdio.h>
#include<stdlib.h>
typedef struct AVLTree{
    int data;
    int height;
    struct AVLTree* left;
    struct AVLTree* right;
}avl;
avl* findMaximum(avl* root){
    if(root==NULL || root->right==NULL)return root;
    findMaximum(root->right);
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
int height(avl* ptr){
    if(ptr==NULL)return -1;
    return ptr->height;
}

// Right rotation
avl* LLRotation(avl* x){
    avl* w = x->left;
    x->left=w->right;
    w->right=x;
    x->height=max(height(x->left),height(x->right))+1;
    w->height=max(height(w->left),x->height)+1;
    return w;
}

// Left rotation
avl* RRRotation(avl* x){
    avl* w = x->right;
    x->right=w->left;
    w->left=x;
    x->height=max(height(x->left),height(x->right))+1;
    w->height=max(height(w->right),x->height)+1;
    return w;
}

// When extra node is present in the left child's right subtree
avl* LRRotation(avl* z){
// left rotation about left child of unbalanced node
    z->left=RRRotation(z->left);
// Right rotation about unbalanced node itself
    return LLRotation(z);
}

// When extra node is present in the Right child's left subtree
avl* RLRotation(avl* z){
// right rotation about left child of unbalanced node
    z->right=LLRotation(z->left);
// Left rotation about unbalanced node itself
    return RRRotation(z);
}

avl* insertion(avl* root,int data){
    if(root==NULL){
        avl* temp =(avl*)malloc(sizeof(avl));
        if(temp==NULL){
            printf("Memory error");
            return NULL;
        }    
        temp->data=data;
        temp->left=temp->right=NULL;
        temp->height=0; 
        root=temp;
    }
    else if (root->data<data){
        root->right=insertion(root->right,data);
        if(height(root->right)-height(root->left)==2){
            if(root->right->data>data){
                root->right=LLRotation(root->right);
            }
            root=RRRotation(root);
        }
    }
    else if(root->data>data){
        root->left=insertion(root->left,data);
        if(height(root->left)-height(root->right)==2){
            if(root->left->data<data){
                root->left=RRRotation(root->left);
            }
            root=LLRotation(root);
        }
    }
    root->height=(max(height(root->left),height(root->right))+1);
    return root;
}
// avl* delete(avl* root,int data){
//     if(root==NULL)return root;
//     else if(root->data<data){
//         root->right=delete(root->right,data);
//         if(height(root->left)-height(root->right)==2){
//              switch(height(root->right->left)-height(root->right->right)){
//                 case 1:
//                 case 0:
//                  root=LLRotation(root);
//                  break;
//                 case -1:
//                  root->left=RRRotation(root->left);
//                  root=LLRotation(root);
//             }
//         }
//     }
//     else if(root->data>data){
//         root->left=delete(root->left,data);
//         if(height(root->right)-height(root->left)==2){
//             switch(height(root->right->left)-height(root->right->right)){
//                 case -1:
//                 case 0:
//                  root=RRRotation(root);
//                  break;
//                 case 1:
//                  root->right=LLRotation(root->right);
//                  root=RRRotation(root);
//             }
//         }
//     }
//     else{
//         if(root->left && root->right){
//             avl* temp = findMaximum(root->left);
//             root->data=temp->data;
//             root->left=delete(root->left,root->data);
//         }
//         else{
//             avl* ptr = root;
//             if(root->left)root=root->left;
//             else{
//                 root=root->right;
//             }
//             free(ptr);
//         }
//     }
//     if(root)
//     root->height=max(height(root->left),height(root->right))+1;
//     return root;
// }
avl*  delete(avl* root,int data){
if(root==NULL)return root;
else if(root->data<data){
root->right=delete(root->right,data);
if(height(root->left)-height(root->right)==2){
	switch(height(root->left->left)-height(root->left->right)){
		case -1:
			root->left=RRRotation(root->left);
		case 0:
		case 1:
			root=LLRotation(root);
}
}
}
else if(root->data>data){
root->left=delete(root->left,data);
if(height(root->right)-height(root->left)==2){
		switch(height(root->right->left)-height(root->right->right)){
		case 1:
			root->right=LLRotation(root->right);
		case 0:
		case -1:
			root=RRRotation(root);
}
}
}
else{
	if(root->left && root->right){
		avl* temp = findMaximum(root->left);
		root->data=temp->data;
		root->left=delete(root->left,root->data);}
	else{
		avl* ptr = root;
		if(root->left)root=root->left;
		else root=root->right;
        free(ptr);
}
}
if(root)
root->height=max(height(root->left),height(root->right))+1;
return root;
}

void inorder(avl* root){
    if(!root)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(avl* root){
    if(!root)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    avl* root = NULL;
    int n;
    for(int i=1;i<=13;i++){
        scanf("%d",&n);
        root=insertion(root,n);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,65);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,60);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,50);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,30);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,70);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,45);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,40);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,52);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,46);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    root=delete(root,44);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
}