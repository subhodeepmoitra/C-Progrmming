#include<stdio.h>

void linearSearch(int a[], int element, int size){
    
    for (int i = 0; i < size; i++)
    {
        if (a[i] == element)
        {
            //return i;
            printf("Found at index %d with loc %p \n", i, (void *)&a[i]);
        }
    }
    printf("Unsuccessful");  
}

int main(){
    int arr[] = {5,10,15,20,25,30};
    int element_search = 10;
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    printf("Sizeof from main %ld\n", sizeof(arr));
    linearSearch(arr, element_search, size_of_array);
    return 0;    
}