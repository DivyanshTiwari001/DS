#include<stdio.h>
void swap(int* a,int* b){
    int t=*b;
    *b=*a;
    *a=t;
}
void selectionSort(int* arr,int len){
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
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
    selectionSort(arr,10);
    printf("\nAfter sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}