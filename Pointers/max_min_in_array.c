#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed...");
        return 1;
    }

    printf("Enter %d elements...", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr+i));
    }
    
    int max = *arr;
    int min = *arr;

    for (int i = 1; i < n; i++)
    {
        if (*(arr+i) > max)
        {
            max = *(arr+i);
        }
        if (*(arr+i) < min)
        {
            min = *(arr+i);
        }
        
    }

    printf("The max element is: %d\n", max);
    printf("The min element is: %d\n", min);

    free(arr);
    return 0;    
    
}