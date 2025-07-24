#include <stdio.h>

void insertionSort(int *arr, int size){
    int i, j;
    for (i=1; i<size; i++){
        int key = arr[i];
        j=i-1; //j refers to i-1th element
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[] = {64,25,12,22,11};
    //int arr[] = {8,7,7,7,2,7,5,7,9,2};
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size_arr);
    int i;
    for(i=0; i<size_arr; i++){
        printf("%d  \n", arr[i]);
    }
    return 0;
}