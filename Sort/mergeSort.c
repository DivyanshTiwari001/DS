#include<stdio.h>
void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}
void mergeSort2(int arr[],int n){
    
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid =l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[5];
    for(int i=0;i<6;i++){
        printf("Enter Number at index %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Before Sorting: ");
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    mergeSort2(arr,6);
    printf("\nAfter sorting: ");
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}