// Q-39
// Given a parent array P, where P[i] indicates the parent of ith node in the tree
// (assume parent of root node is indicated with –1). Give an algorithm for finding the height
// or depth of the tree.
#include"library.h"
#include<stdio.h>
#include<stdlib.h>
int heightOfTree(int* arr,int length){
    int i=0,maxi=0;
    while(i<length){
        int j=i,count=0;
        while(arr[j]!=-1){
            if(arr[j]>=length){
                printf("Err: Wrong Input");
                exit(1);
            }
            j=arr[j];
            count++;
        }
        i++;
        maxi=max(count,maxi);
    }
    return maxi;
}
int main(){
    int arr[]={-1,0,1,6,6,0,0,2,7,8};
    printf("Height of the tree is %d",heightOfTree(arr,10));
}