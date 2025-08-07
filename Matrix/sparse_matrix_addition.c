#include<stdio.h>

/*
Steps:
1. Take 2 matrices from user
2. Check for sparse
3. Convert the sparse to triplet
4. Do the addition of the triplet matrices
5. Display the result of the triplet matrices
*/
void displayMatrix(int row, int col, int matrix[row][col]){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    
}
void addTriplet(int c1, int triplet1[c1][3], int c2, int triplet2[c2][3], int row, int col){
    int result[c1+c2][3];
    int i=0, j=0, k=0;
    while (i<c1 && j<c2)
    {
        if(triplet1[i][0] < triplet2[j][0] || (triplet1[i][0]==triplet2[j][0] && triplet1[i][1]<triplet2[j][1])){
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2];
            i++; k++;
        }
        else if (triplet2[j][0] < triplet1[i][0] || triplet2[i][0] && triplet2[j][1] < triplet1[i][1])    
        {
            result[k][0] = triplet2[j][0];
            result[k][1] = triplet2[j][1];
            result[k][2] = triplet2[j][2];
            j++; k++;
        } else {
            //for same row ,col index
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2]+triplet2[j][2];
            i++; j++; k++;
        }
        
    }
    while (i<c1)
    {
        result[k][0] = triplet1[i][0];
        result[k][1] = triplet1[i][1];
        result[k][2] = triplet1[i][2];
        i++; k++;
    }
    while(j<c2){
        result[k][0] = triplet2[j][0];
        result[k][1] = triplet2[j][1];
        result[k][2] = triplet2[j][2];
        j++; k++;
    }
    printf("\n The added triplet matrix is: \n");
    for (int x = 0; x < k; x++)
    {
        printf("%4d %4d %4d \n", result[x][0], result[x][1], result[x][2]);
    }
    //optionally convert to dense matrix directly
    int dense[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            dense[i][j] = 0; //default populating with 0
        }
        
    }
    for (int x = 0; x < k; x++)
    {
        dense[result[x][0]][result[x][1]] = result[x][2];
    }
    printf("\n The dense matrix after addition: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d", dense[i][j]);
        }
        printf("\n");
        
    }
        
}
void sparseRepresentation(int r1, int c1, int r2, int c2, int matrix1[r1][c1], int matrix2[r2][c2]){
    int non_zero1=0, non_zero2=0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if(matrix1[i][j] != 0){
                non_zero1++;
            }
        }
        
    }
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if(matrix2[i][j] != 0){
                non_zero2++;
            }
        }
        
    }
    int triplet1[non_zero1][3], k1=0;
    int triplet2[non_zero2][3], k2=0;
    //generating triplet for matrix1
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if(matrix1[i][j] != 0){
                triplet1[k1][0]=i;
                triplet1[k1][1]=j;
                triplet1[k1][2]=matrix1[i][j];
                k1++;
            }
        }
        
    }
    //generating triplet for matrix2
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if(matrix2[i][j] != 0){
                triplet2[k2][0]=i;
                triplet2[k2][1]=j;
                triplet2[k2][2]=matrix2[i][j];
                k2++;
            }
        }
        
    }
    printf("Showing triplet of matrix1: \n");
    displayMatrix(non_zero1, 3, triplet1);
    printf("Showing triplet of matrix2: \n");
    displayMatrix(non_zero2, 3, triplet2);
    addTriplet(non_zero1, triplet1, non_zero2, triplet2, r1, c1);
}

int main(){
    int r1, c1, r2, c2;
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &r1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &c1);
    int matrix1[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter element at %d,%d of matrix1: ", i,j);
            scanf("%d", &matrix1[i][j]);
        }
        
    }
    printf("Displaying matrix1: \n");
    displayMatrix(r1, c1, matrix1);
    
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &r2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &c2);
    int matrix2[r2][c2];
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Enter element at %d,%d of matrix2: ", i,j);
            scanf("%d", &matrix2[i][j]);
        }
        
    }
    printf("Displaying matrix2: \n");
    displayMatrix(r2, c2, matrix2);

    printf("Attempting to convert matrix1&2 to triplet... \n");
    sparseRepresentation(r1, c1, r2, c2, matrix1, matrix2);
    

}