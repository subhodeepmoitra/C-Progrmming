#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed...");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;    
    
}