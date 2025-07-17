#include<stdio.h>

int main(){
    int a[10] = {34, 24, 56, 31, 68, 88, 91, 33, 22, 6};
    int i; //to loop iterator
    for (i=0; i<10; i++){
        // Print the array in original order
        printf("%d ", a[i]);
    }
    printf("\n"); // New line
    for (i=9; i>=0; i--){
        // Array in reverse
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}