#include"binarytree.h"
void traversalZigZag(bt* root){
    st* s1=createStack(); 
    st* s2=createStack();
    push(&s1,root); 
    while(isEmptyStack(s1)!=1 || isEmptyStack(s2)!=1 ){
        if(!isEmptyStack(s1)){
            while(!isEmptyStack(s1)){
                bt* temp=pop(&s1);
                printf("%d ",temp->data);
                if(temp->left){
                    push(&s2,temp->left);
                }
                if(temp->right){
                    push(&s2,temp->right);
                }
            }
        }
        else if(!isEmptyStack(s2)){
            while(!isEmptyStack(s2)){
                bt* temp=pop(&s2);
                printf("%d ",temp->data);
                if(temp->right){
                    push(&s1,temp->right);
                }
                if(temp->left){
                    push(&s1,temp->left);
                }
            }
        }
    }
    DeleteStack(&s1);
    DeleteStack(&s2);
}
int main(){
    // bt* root = createTree();
    bt* root = NULL;
    for(int i=0;i<15;i++){
        insertInTree(&root,i+1);
    }
    levelTraversal(root);
    printf("\n");
    traversalZigZag(root);

    return 0;
}