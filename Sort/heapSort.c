#include <stdio.h>
 
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    heapSort(arr,10);
    printf("\nAfter sorting: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}