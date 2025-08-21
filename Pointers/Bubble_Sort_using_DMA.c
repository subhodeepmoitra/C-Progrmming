#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1]) //*(arr+j) > *(arrj+1) if using pointer arithmetic
            {
                int temp = arr[j]; // int temp = *(arr+j)
                arr[j] = arr[j+1]; // *(arr+j) = *(arr+j+1)
                arr[j+1] = temp; // *(arr+j+1) = temp
            }
            
        }
        
    }
    
}

int main(){
    int n;
    int *arr;

    printf("Enter the no of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n*sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed...");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    display(arr, n);
    return 0;
}