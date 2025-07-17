#include<stdio.h>

void reverseArray(int *a, int n){
    printf("Reverse array \n");
    for (int i = n-1; i >= 0; i--)
    {
        printf("Element is %d at %p \n", a[i], (void *)&a[i]);
    }
    printf("Sizeof from reverseArray() %ld\n", sizeof(a));
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("The original order: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Element is %d at %p \n", arr[i], (void *)&arr[i]);
    }
    printf("Sizeof from main %ld\n", sizeof(arr));
    reverseArray(arr,n);
    return 0;
    
}