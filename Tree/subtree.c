#include"binarytree.h"
int checkSubTree(bt* root1,bt* root2){
    if(!root1 && !root2){
        return 1;
    }
    else if(!root1 || !root2){
        return 0;
    }
    else{
        if(root1->data == root2->data){
            return checkSubTree(root1->left,root2->left) && checkSubTree(root1->right,root2->right);
        }
        else{
            return checkSubTree(root1->left,root2) || checkSubTree(root1->right,root2);
        }
    }
}
bt* mirrorTree(bt* root){
    if(!root)return NULL;
    else{
        bt* n = (bt*)malloc(sizeof(bt));
        n->data = root->data;
        n->left=n->right=NULL;
        if(root->right)
            n->left=mirrorTree(root->right);
        if(root->left)
            n->right=mirrorTree(root->left);
        return n; 
    }
}
int main(){
    bt* root=NULL;
    for(int i=0;i<10;i++){
        insertInTree(&root,i+1);
    }
    levelTraversal(root);
    printf("\n");
    bt* root2=mirrorTree(root);
    levelTraversal(root2);
}