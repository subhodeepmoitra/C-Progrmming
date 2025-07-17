#include <stdio.h>

void printArray(int *a, int size){
    for(int i=0; i<size; i++){
        printf("%d at loc %p \n", a[i], (void *)&a[i]);
    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printArray(arr, size);
    return 0;
}