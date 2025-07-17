#include <stdio.h>

void main(){
    int array_limit, count=0;
    printf("Enter the size of array: ");
    scanf ("%d", &array_limit);
    int array[array_limit];
    for (int i=0; i<array_limit; i++){
        if (i==0){
            count=0;
            printf("Enter element at pos %d:",count);
            scanf("%d", &array[i]);
        }
        else {
        count++;
        printf("Enter element at pos %d:",count);
        scanf("%d", &array[i]);
        }
    }
    printf("The array elements are: \n");
    for (int i=0; i<array_limit; i++){
        if (i==0){
            count=0;
            printf("Element at pos %d is: %d", count, array[i]);
            printf("\n");
        }
        else{
        count++;
        printf("Element at pos %d is: %d", count, array[i]);
        printf("\n");
        }        
    }
}