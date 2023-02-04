#include<stdio.h>
#include<string.h>
int main(){
    char List[50][100];
    int n;
    printf("Enter the Number of elements you want to add in list\n");
    scanf("%d",&n);
    printf("Kindly Enter items in your List\n");
    for(int i=0;i<n;i++){
        scanf(" %[^\n]%*c",List[i]);
    }
    printf("You have entered Following things in your list\n");
    for(int i=0;i<n;i++){
        printf("%d: %s\n",i+1,List[i]);
    }
}