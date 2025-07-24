#include <stdio.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]){
    int i,j;
    for(i=0; i<rows; i++){
        for (j=0; j<cols; j++){
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    // matrix[rows][columns]
    int a[3][3] = {{1,2,3},
                   {4,5,6},
                   {10,20,30}};
    int b[3][3] = {{7,8,9},
                   {10,11,12},
                   {40,50,60}};
    int add[3][3]; //matrix init for storing the resulting matrix
    printf("Display matrix A: \n");
    printMatrix(3,3,a);
    printf("Display matrix B: \n");
    printMatrix(3,3,b);
    return 0;
}