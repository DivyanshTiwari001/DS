#include<stdio.h>
int linearSearch(int * arr,int len,int key){
    for(int i=0;i<len;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[100],n,key,index=-1;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the element at index %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the key you want to search for: ");
    scanf("%d",&key);
    index=linearSearch(arr,n,key);
    if(index==-1){
        printf("Sorry!,This element is not there in your array\n");
    }
    else{
        printf("The index of %d is %d",key,index);
    }
    return 0;
}