#include <stdio.h>

int main(){
    int size_of_array;
    printf("Enter the size of the array: ");
    scanf("%d", &size_of_array);
    int arr[size_of_array];
    for (int i=0; i<size_of_array; i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("The array elements are: \n");
    for (int i=0; i<size_of_array; i++){
        printf("%d at loc %p \n", arr[i], (void *)&arr[i]);
    }
    printf("\n");
    return 0;
}