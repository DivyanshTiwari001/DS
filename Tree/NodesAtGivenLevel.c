#include"binarytree.h"
void NodesAtGivenLevel(bt* root,int level){
    if(root==NULL)return;
    Queue* Q =createQueue();
    int curLevel=0;
    EnQueue(Q,root);
    EnQueue(Q,NULL);
    while(!IsQueueEmpty(Q)){
        bt* temp = DeQueue(Q);
        if(temp==NULL){
            if(curLevel<level){
                EnQueue(Q,NULL);
                curLevel++;
            }
            else if(curLevel==level)return;
        }else{
        if(curLevel==level){
            printf("%d ",temp->data);
        }
        else{
            if(temp->left!=NULL)EnQueue(Q,temp->left);
            if(temp->right!=NULL)EnQueue(Q,temp->right);
        }
    }
    }
}
int main(){
    bt* root = NULL;
    for(int i = 0; i<10;i++){
        insertInTree(&root,i+1);
    }
    levelTraversal(root);
    printf("\n");
    NodesAtGivenLevel(root,2);
}