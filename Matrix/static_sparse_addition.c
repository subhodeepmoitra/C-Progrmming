#include <stdio.h>
#define ROW 100
#define COL 100

void displayMatrix(int row, int column, int a[ROW][COL]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

void displayTriplet(int rows, int triplet[][3]) {
    for (int i = 0; i < rows; i++) {
        printf("%4d %4d %4d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

void TripletToDense(int triplet[][3], int dense[ROW][COL]) {
    int nonZero = triplet[0][2];
    for (int i = 1; i <= nonZero; i++) {
        int r = triplet[i][0];
        int c = triplet[i][1];
        dense[r][c] = triplet[i][2];
    }
}

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

void convertToTriplet(int row, int column, int sparse[ROW][COL], int triplet[][3]) {
    int k = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (sparse[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    triplet[0][0] = row;
    triplet[0][1] = column;
    triplet[0][2] = k - 1;
}


void addTriplets(int t1[][3], int t2[][3], int tSum[][3]) {// Func. to add two sparse matrices in triplet form
    int i = 1, j = 1, k = 1;
    int rows = t1[0][0], cols = t1[0][1];

    // Setting header
    tSum[0][0] = rows;
    tSum[0][1] = cols;

    while (i <= t1[0][2] && j <= t2[0][2]) {
        if (t1[i][0] < t2[j][0] || 
           (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            tSum[k][0] = t1[i][0];
            tSum[k][1] = t1[i][1];
            tSum[k][2] = t1[i][2];
            i++; k++;
        }
        else if (t2[j][0] < t1[i][0] || 
                (t2[j][0] == t1[i][0] && t2[j][1] < t1[i][1])) {
            tSum[k][0] = t2[j][0];
            tSum[k][1] = t2[j][1];
            tSum[k][2] = t2[j][2];
            j++; k++;
        }
        else {
            int sumVal = t1[i][2] + t2[j][2];
            if (sumVal != 0) {
                tSum[k][0] = t1[i][0];
                tSum[k][1] = t1[i][1];
                tSum[k][2] = sumVal;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= t1[0][2]) {
        tSum[k][0] = t1[i][0];
        tSum[k][1] = t1[i][1];
        tSum[k][2] = t1[i][2];
        i++; k++;
    }
    while (j <= t2[0][2]) {
        tSum[k][0] = t2[j][0];
        tSum[k][1] = t2[j][1];
        tSum[k][2] = t2[j][2];
        j++; k++;
    }

    tSum[0][2] = k - 1; // total non-zeros
}

int main() {
    int row, column;
    int sparse1[ROW][COL] = {0}, sparse2[ROW][COL] = {0}, dense[ROW][COL] = {0};

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &column);

    int triplet1[(int)(ROW * COL * 0.3)][3];
    int triplet2[(int)(ROW * COL * 0.3)][3];
    int tripletSum[(int)(ROW * COL * 0.3)][3];

    printf("First Sparse Matrix: \n");
    createSparseMatrix(row, column, sparse1);
    printf("Sparse Matrix 1:\n");
    displayMatrix(row, column, sparse1);
    convertToTriplet(row, column, sparse1, triplet1);

    printf("Second Sparse Matrix:\n");
    createSparseMatrix(row, column, sparse2);
    printf("Sparse Matrix 2:\n");
    displayMatrix(row, column, sparse2);
    convertToTriplet(row, column, sparse2, triplet2);

    printf("\nTriplet 1:\n");
    displayTriplet(triplet1[0][2] + 1, triplet1);
    printf("\nTriplet 2:\n");
    displayTriplet(triplet2[0][2] + 1, triplet2);

    
    addTriplets(triplet1, triplet2, tripletSum); // Add the matrices

    printf("\nSum Triplet:\n");
    displayTriplet(tripletSum[0][2] + 1, tripletSum);

    TripletToDense(tripletSum, dense);    // Convert sum triplet to dense for display

    printf("\nDense Matrix from Sum Triplet:\n");
    displayMatrix(row, column, dense);

    return 0;
}
