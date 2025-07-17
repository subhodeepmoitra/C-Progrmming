#include<stdio.h>

int main(){
    int arr[3] = {3,6,9};
    for(int i=0; i<3; i++){
        printf("%d at loc %p \n", arr[i], (void *)&arr[i]);
    }
    printf("\n");
    return 0;
}