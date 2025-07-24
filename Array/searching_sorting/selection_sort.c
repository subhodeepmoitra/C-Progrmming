#include <stdio.h>

void selectionSort(int *arr, int size_arr){
    int i, j, min_index, temp;
    // i -> marks the start of the unsorted array (main loop)
    // j -> scanning through every element in that unsorted part to find the minimum (loop for finding the and updating the min element)
    for(i=0; i<size_arr-1; i++){
        //find the min element in the unsorted array
        min_index = i;
        for(j=i+1; j<size_arr; j++){
            if(arr[j] < arr[min_index]){
                min_index=j;
            }

        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        /*if(min_index != i){
            // To increase efficiency and not mandatory
            // If this is True then this means that the current element i is not the smallest so swap
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }*/

    }
}

int main(){
    int arr[] = {64,25,12,22,11};
    //int arr[] = {8,7,7,7,2,7,5,7,9,2};
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size_arr);
    int i;
    for(i=0; i<size_arr; i++){
        printf("%d  \n", arr[i]);
    }
    return 0;
}