#include<stdio.h>

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int *arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr, j, j+1);
            }
            
        }
        
    }
    
}

int main(){
    int arr[] = {6,5,10,7, 10, 15, 0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}