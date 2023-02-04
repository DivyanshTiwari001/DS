#include<stdio.h>
#include<limits.h>
int findMax(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void cummulateFrequency(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        arr[i]=sum;
    }
}
void frequencyTable(int arr[],int cummulate[],int n){
    for(int i=0;i<n;i++){
        cummulate[arr[i]]+=1;
    }
}
void countSort(int arr[],int n){
    int max=findMax(arr,n);
    int cummulate[max+1];
    for(int i=0;i<=max;i++){
        cummulate[i]=0;
    }
    frequencyTable(arr,cummulate,n);
    cummulateFrequency(cummulate,max+1);
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    for(int i=n-1;i>=0;i++){
        arr[--cummulate[temp[i]]]=temp[i];
    }
}
int main(){
    int arr[]={8,5,1,4,2,6,5}
}
