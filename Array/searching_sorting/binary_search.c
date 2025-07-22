// The array needs to be sorted already
#include <stdio.h>

int binarySearch(int *array, int lower, int upper, int key){
    int mid;
    while(lower <= upper){
        mid = lower + (upper-lower) / 2;
        
        //if key == arr[mid]
        if(array[mid] == key){
            return mid;
        }
        // if key > mid element, ignore left half
        if(array[mid] < key){
            lower = mid+1;
        }
        // otherwise if key < mid element, ignore right half
        else {
            upper = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    int key = 1000;
    int status = binarySearch(arr, 0, size_of_array-1, key);
    if (status == -1){
        printf("Unsuccessful \n");
    } else {
        printf("Success at [%d]\n", status);
    }
    return 0;
}