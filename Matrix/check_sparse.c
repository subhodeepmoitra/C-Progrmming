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

void sparseMatrixRepresentation(int row, int column, int matrix[row][column]){
    int non_zero=0, zero=0;
    for(int i=0; i<row; i++){
        for(int j=0;j <column; j++){
            if(matrix[i][j] != 0){
                non_zero++;
            } else {
                zero++;
            }
        }
    }
    int sparse_matrix[non_zero][3], k=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(matrix[i][j] != 0){
                sparse_matrix[k][0] = i;
                sparse_matrix[k][1] = j;
                sparse_matrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("The sparse matrix representation is: \n");
    displayMatrix(non_zero, 3, sparse_matrix);    

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
        sparseMatrixRepresentation(row, column, matrix);
    } else {
        printf("Sparse not confirmed \n");
    }
    return 0;
}