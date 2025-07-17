#include<stdio.h>

void printArray(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\n", a[i]);
        printf("Add: %p\n", (void*)&a[i]);
    }
    printf("Sizeof from func: %ld\n", sizeof(a));
    
}

int main(){
    int arr[5]={10,20,30,40,50};
    int *ptr = arr; //array decays into pointer
    printf("Element, %d\n", *(ptr+2));
    printf("Sizeof, %ld\n", sizeof(arr));
    printArray(arr, 5);
    return 0;
}