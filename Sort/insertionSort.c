#include<stdio.h>
void swap(int* a,int* b){
    int t=*b;
    *b=*a;
    *a=t;
}
void insertionSort(int* arr,int len){
    for(int i=0;i<len;i++){
        int j=i;
        int data=arr[j];
        while(j>0 && arr[j-1]>data){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=data;
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
    insertionSort(arr,10);
    printf("\nAfter sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}