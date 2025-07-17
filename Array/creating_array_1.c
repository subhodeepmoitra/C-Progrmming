#include<stdio.h>
int main(){
    int array_limit;
    printf("Enter the size of the array: ");
    scanf("%d",&array_limit);
    int array[array_limit];
    for (int i = 0; i < array_limit; i++)
    {
        /* code */
        printf("Enter element at pos %d: ", i);
        scanf("%d", &array[i]);
        //printf("\n");
    }

    for (int i = 0; i < array_limit; i++)
    {
        // Original order
        printf("%d ",array[i]);
    }
    printf("\n");

    for (int i=array_limit-1; i>=0; i--){
        // Reverse Order
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
    
}