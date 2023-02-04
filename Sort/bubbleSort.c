#include<stdio.h>
void swap(int* a,int* b){
    int t=*b;
    *b=*a;
    *a=t;
}
void bubbleSort(int* arr,int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
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
    bubbleSort(arr,10);
    printf("\nAfter sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}