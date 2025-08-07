#include<stdio.h>

// Prototype declaration
int checkSparse(int row, int column, int matrix[row][column]);
void displayMatrix(int row, int column, int matrix[row][column]);
void sparseMatrixRepresentation(int row, int column, int matrix[row][column]);
void tripletToDense(int row, int column, int non_zero, int triplet_representation[non_zero][3]);

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
    int sparse_matrix_representation[non_zero][3], k=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(matrix[i][j] != 0){
                sparse_matrix_representation[k][0] = i; //set row
                sparse_matrix_representation[k][1] = j; //set column
                sparse_matrix_representation[k][2] = matrix[i][j]; //set value of row,column position
                k++; //increment k to accomodate the next non zero elements
            }
        }
    }
    printf("The sparse matrix representation is: \n");
    displayMatrix(non_zero, 3, sparse_matrix_representation);
    printf("Attempting to convert this sparse representation to it's dense form... \n");
    tripletToDense(row, column, non_zero, sparse_matrix_representation);

}

void tripletToDense(int row, int column, int non_zero, int triplet_representation[non_zero][3]){
    int dense[row][column];
    //initialize the dense matrix with 0
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            dense[i][j] = 0;
        }
    }
    //fill the non_zero values from the triplet representation
    for (int i = 0; i < non_zero; i++)
    {
        int r = triplet_representation[i][0]; //row
        int c = triplet_representation[i][1]; //column
        int value = triplet_representation[i][2]; //fetch value
        dense[r][c] = value; //set the value to the row,column position
    }
    printf("The dense matrix converted from triplet representation is: \n");
    displayMatrix(row, column, dense);
    
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