#include<stdio.h>

int checkSparse(int row, int column, int matrix[row][column]){
    int zero=0, non_zero=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(matrix[i][j] == 0){
                zero++;
            } else {
                non_zero++;
            }
        }
    }

    if (zero > non_zero){
        return 1;
    } else {
        return 0;
    }
}

void displayMatrix(int row, int column, int matrix[row][column]){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int row, column;
    printf("Enter the number of rows: ");
    scanf("%d",&row);
    printf("Enter the number of columns: ");
    scanf("%d",&column);
    int matrix[row][column];
    printf("Enter the elements of the matrix--- \n");
    for(int i=0;i<row;i++){
        for(int j=0; j<column; j++){
            printf("Element at pos %d,%d: ", i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    displayMatrix(row, column, matrix);
    int status = checkSparse(row, column, matrix);
    if(status == 1){
        printf("Sparse Confirmed: Needs Representation \n");
        // representation function to be called here
    } else {
        printf("Sparse not confirmed \n");
    }
    return 0;
}