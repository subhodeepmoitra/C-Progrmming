#include <stdio.h>
#define ROW 100
#define COL 100
#define TRIPLET_ROWS (ROW * COL + 1) // +1 for header

// Display dense matrix
void displayMatrix(int row, int column, int a[ROW][COL]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

// Display triplet matrix
void displayTriplet(int rows, int triplet[TRIPLET_ROWS][3]) {
    for (int i = 0; i < rows; i++) {
        printf("%4d %4d %4d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

// Display dense matrix reconstructed from triplet
void displayTripletAsDense(int tripletRows, int triplet[TRIPLET_ROWS][3]) {
    int row = triplet[0][0]; //header row
    int col = triplet[0][1]; //header col
    int nonZero = triplet[0][2]; //header no. of non zero elements

    int dense[ROW][COL] = {0};

    for (int i = 1; i <= nonZero; i++) {
        int r = triplet[i][0]; //row
        int c = triplet[i][1]; //col
        int val = triplet[i][2]; //val
        dense[r][c] = val; //insert val to row,col index
    }

    displayMatrix(row, col, dense);
}

// Create sparse matrix
void createSparseMatrix(int row, int column, int a[ROW][COL]) {
    char choice;
    int r, c, val;

    do {
        printf("Do you want to add a non-zero element? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Enter row, column, and value: ");
            scanf("%d %d %d", &r, &c, &val);
            a[r][c] = val;
        }
    } while (choice == 'y' || choice == 'Y');
}

// Convert sparse to triplet and display
void convertToTripletAndDisplay(int row, int column, int sparse[ROW][COL]) {
    int triplet[TRIPLET_ROWS][3];
    int nonZeroCount = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (sparse[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    triplet[0][0] = row; //header row
    triplet[0][1] = column; //header col
    triplet[0][2] = nonZeroCount; //header no. of non zero

    int k = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (sparse[i][j] != 0) {
                triplet[k][0] = i; //row
                triplet[k][1] = j; //col
                triplet[k][2] = sparse[i][j]; //val
                k++; //increament the row counter by 1
            }
        }
    }

    printf("\nTriplet Form:\n");
    displayTriplet(nonZeroCount + 1, triplet);

    printf("\nDense Matrix from Triplet:\n");
    displayTripletAsDense(nonZeroCount + 1, triplet);
}

int main() {
    int row, column;
    int sparse[ROW][COL] = {0};

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &column);

    createSparseMatrix(row, column, sparse);

    printf("\nSparse Matrix:\n");
    displayMatrix(row, column, sparse);

    convertToTripletAndDisplay(row, column, sparse);

    return 0;
}
