#include<stdio.h>
#define MAX 100

void rotate(int matrix[][MAX], int row, int col) {
    int i, j, t;
    // Rotate only top 1/4 of the matrix by 90 degree
    // Caution: boundary of i and j!
    for (i = 0; i < (row-1)/2+1; ++i) {
        for (j = 0; j < col/2; ++j) {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][col-1-i];
            matrix[j][col-1-i] = matrix[row-1-i][col-1-j];
            matrix[row-1-i][col-1-j] = matrix[row-1-j][i];
            matrix[row-1-j][i] = t;
        }
    }
}

void print_matrix(int matrix[][MAX], int row, int col) {
    int i, j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX];
    int row, col, i, j;
    scanf("%d %d", &row, &col);
    if (row > MAX || col > MAX) {
        printf("Too big to handle\n");
        return 1;
    }

    // Read in the matrix
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    print_matrix(matrix, row, col);
    printf("\n");
    rotate(matrix, row, col);
    print_matrix(matrix, row, col);
    printf("\n");
}
