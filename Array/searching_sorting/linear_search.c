#include<stdio.h>

int linearSearch(int *array, int size, int element){
    int i;
    for(i=0; i<size; i++){
        if(element==array[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    int size_of_array, i, element_to_search, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size_of_array);
    int array[size_of_array];
    for(i=0; i<size_of_array; i++){
        printf("Enter %d th element: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &element_to_search);
    result = linearSearch(array, size_of_array, element_to_search);
    if(result != -1){
        printf("Success at index %d at position %d", result, result+1);
    }
    else {
        printf("Failed");
    }
    return 0;
}