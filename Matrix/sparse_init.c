#include <stdio.h>
#define ROW 100
#define COL 100

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
void displayTriplet(int rows, int triplet[][3]) {
    for (int i = 0; i < rows; i++) {
        printf("%4d %4d %4d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

// create dense matrix reconstructed from triplet
//void TripletToDense(int tripletRows, int triplet[][3], int dense[ROW][COL]) {
void TripletToDense(int triplet[][3], int dense[ROW][COL]) {
    int nonZero = triplet[0][2]; //since the no. of non zero elements are present in the 3rd column of the triplet header

    // Directly fill the passed-in already-zeroed matrix
    for (int i = 1; i <= nonZero; i++) {
        int r = triplet[i][0];
        int c = triplet[i][1];
        int val = triplet[i][2];
        dense[r][c] = val;
    }
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
//void convertToTriplet(int row, int column, int sparse[ROW][COL], int triplet[ROW * COL + 1][3]) {
void convertToTriplet(int row, int column, int sparse[ROW][COL], int triplet[][3])  // no fixed bound
{    
    int k = 1; // index for triplet rows starting from 1 since 0 is header
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (sparse[i][j] != 0) {
                triplet[k][0] = i; // row
                triplet[k][1] = j; // col
                triplet[k][2] = sparse[i][j]; // value
                k++;
            }
        }
    }

    triplet[0][0] = row; // header-> total rows
    triplet[0][1] = column;// header-> total columns
    triplet[0][2] = k - 1;// header-> total non-zero count

    //return k;
}

int main() {
    int row, column;
    int sparse[ROW][COL] = {0};   // all zeros at start
    int triplet[(int)(ROW * COL * 0.3)][3]; //30%
    int dense[ROW][COL] = {0};    // all zeros at start

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &column);

    //createSparseMatrix(row, column, sparse);

    //printf("\nSparse Matrix:\n");
    //displayMatrix(row, column, sparse);

    //convertToTriplet(row, column, sparse, triplet);

    //printf("\nTriplet Form:\n");
    //displayTriplet(triplet[0][2] + 1, triplet);  // header + data rows

    //TripletToDense(triplet[0][2] + 1, triplet, dense);

    //printf("\nDense Matrix from Triplet:\n");
    //displayMatrix(row, column, dense);

    createSparseMatrix(row, column, sparse);

    printf("\nSparse Matrix:\n");
    displayMatrix(row, column, sparse);

    convertToTriplet(row, column, sparse, triplet);

    printf("\nTriplet Form:\n");
    displayTriplet(triplet[0][2] + 1, triplet);

    TripletToDense(triplet, dense);

    printf("\nDense Matrix from Triplet:\n");
    displayMatrix(row, column, dense);

    return 0;
}
