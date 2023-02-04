#include<stdio.h>
#include"library.h"
int partition(int* arr,int low,int high){
    int left=low,right=high,pivot_point=arr[low];
    while(left<right){
        while(arr[left]<=pivot_point){
            left++;
        }
        while(arr[right]>pivot_point){
            right--;
        }
        if(left<right){
            swap(&arr[left++],&arr[right++]);
        }
    }
    arr[low]=arr[right];
    arr[right]=pivot_point;
    return right;
}
void quickSort(int *arr,int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        printf("Enter Number at index %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Before Sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    quickSort(arr,0,10);
    printf("\nAfter sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}