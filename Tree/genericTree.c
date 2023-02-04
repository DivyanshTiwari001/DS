// Generic Tree have nodes which can have 0,1,2,or more child nodes
// We use first child-next sibling representation for Generic tree to minimize the memory loses and overcome the problem of not knowing how many child nodes each have;
#include<stdio.h>
#include<stdlib.h>
#include"library.h"
typedef struct GenericTree{
    int data;
    struct GenericTree* firstChild;
    struct GenericTree* nextSibling;
}gt;

// sum of all elements
int sum(gt* root){
    if(!root)return 0;
    return root->data+sum(root->firstChild)+sum(root->nextSibling);
}

// Total siblings of a node
int sibling(gt* node){
    int count=0;
    while(node!=NULL){
        node=node->nextSibling;
        count++;
    }
    return count;
}

// isomorphic Tree
int isomorphicTree(gt* root1, gt* root2){
    if(root1==NULL && root2 == NULL){
        return 1;
    }
    else if( root1!=NULL && root2!=NULL){
        return isomorphicTree(root1->firstChild,root2->firstChild) && isomorphicTree(root1->nextSibling,root2->nextSibling);
    }
    else{
        return 0;
    }
}

// Dynamic function to create Tree
gt* createTree(){
    gt* n=(gt* )malloc(sizeof(gt));
    printf("Enter the value of the node: ");
    scanf("%d",&(n->data));
    n->firstChild=n->nextSibling=NULL;
    printf("Do %d have child node[y/n]: ",n->data);
    char c;//choice
    scanf(" %c",&c);
    if(c=='y'){
        n->firstChild=createTree();
    }
    printf("Do %d have sibling node[y/n]: ",n->data);
    scanf(" %c",&c);
    if(c=='y'){
        n->nextSibling=createTree();
    }
    return n;
}
int main(){
    gt* root1 =createTree();
    gt* root2 =createTree();
    printf("Sum is: %d",sum(root1));
    printf("\nSibilings of root node:%d",sibling(root1));
    printf("\nSibilings of %d node:%d",root1->firstChild->data,sibling(root1->firstChild));
    printf("\nIs root1 isomorphic to root2: %d",isomorphicTree(root1,root2));
}