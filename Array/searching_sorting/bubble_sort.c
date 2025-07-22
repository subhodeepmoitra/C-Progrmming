#include<stdio.h>

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int *arr, int size_of_array){
    int i, j;
    for(i=0; i<size_of_array-1; i++){
        // Considering the fact that the last ith element will always sorted
        for(j=0; j<size_of_array-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}
int main(){
    int i;
    int arr[] = {8,7,7,7,3,7,6,7,9,2};
    int size_of_arr = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size_of_arr);
    for(i=0; i<size_of_arr; i++){
        printf("%d", arr[i]);
    }
    return 0;
}