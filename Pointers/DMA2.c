#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr = NULL;
    int n=0;
    char choice;

    do
    {
        n++;
        arr = (int *)realloc(arr, n*sizeof(int));
        if (arr == NULL)
        {
            printf("Memory Allocation Failed...");
            return 1;
        }
        printf("Enter element %d: ", n);
        scanf("%d", &arr[n-1]);

        printf("Do you want to add element (Y/N): ");
        scanf(" %c", &choice);
        
    } while ((choice == 'Y') || (choice == 'y'));

    printf("The elements are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
    
}