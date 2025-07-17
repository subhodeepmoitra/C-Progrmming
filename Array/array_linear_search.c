#include<stdio.h>

int linearSearch(int a[], int element, int size){
    //printf("Sizeof from linearSearch() %ld \n", sizeof(a));
    for (int i = 0; i < size; i++)
    {
        if (a[i] == element)
        {
            return i;
        }
    }
    return -1;    
}

int main(){
    int arr[] = {5,10,15,20,25,30};
    int element_search = 20;
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    printf("Sizeof from main %ld\n", sizeof(arr));
    int result = linearSearch(arr, element_search, size_of_array);
    if (result == -1)
    {
        printf("Unsuccessful\n");
    } else {
        printf("Successful at index %d\n", result);
    }
    
}