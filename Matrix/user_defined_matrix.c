#include<stdio.h>

void displayMatrix(int rows, int columns, int matrix[rows][columns]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int r1, c1;
    printf("Enter details of Matrix 1(A): \n");
    printf("Enter the number of rows: ");
    scanf("%d", &r1);
    printf("Enter the number of columns: ");
    scanf("%d",&c1);
    if(r1 <= 0 || c1 <= 0){
        printf("Error: Can't define");
        return -1;
    }
    int matrix1[r1][c1];
    printf("Enter the elements of Matrix 1(A): \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Enter element at pos (%d,%d): ", i+1, j+1);
            scanf("%d",&matrix1[i][j]);
        }
    }

    int r2, c2;
    printf("Enter details of Matrix 2(B): \n");
    printf("Enter the number of rows: ");
    scanf("%d", &r2);
    printf("Enter the number of columns: ");
    scanf("%d",&c2);
    if(r2 <= 0 || c2 <= 0){
        printf("Error: Can't define");
        return -1;
    }
    int matrix2[r2][c2];
    printf("Enter the elements of Matrix 2(B): \n");
    for (int i = 0; i < r2; i++)
    {
       for (int j = 0; j < c2; j++)
       {
         printf("Enter element at pos (%d,%d): ", i+1, j+1);
         scanf("%d", &matrix2[i][j]);
       }
       
    }

    displayMatrix(r1,c1,matrix1);
    printf("------------\n");
    displayMatrix(r2,c2,matrix2);
    return 0;
}