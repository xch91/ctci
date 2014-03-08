#include<stdio.h>
#include<string.h>
#define MAX 100

void print_matrix(int matrix[][MAX], int row, int col) {
    int i, j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zero_out(int matrix[][MAX], int row, int col, int zr[], int zc[], int len) {
    int i, j;
    for (i = 0; i < len; ++i) {
        memset(matrix[zr[i]], 0, col*(sizeof(int)));
    }
    for (i = 0; i < len; ++i) {
        for (j = 0; j < row; ++j) {
            matrix[j][zc[i]] = 0;
        }
    }
}

int main() {
    int matrix[MAX][MAX];
    int row, col, i, j, len = 0;
    int zr[MAX], zc[MAX];
    scanf("%d %d", &row, &col);
    if (row > MAX || col > MAX) {
        printf("Too big to handle\n");
        return 1;
    }

    for (i = 0; i < row; ++i) {
        for (j = 0; j < row; ++j) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0) {
                zr[len] = i;
                zc[len++] = j;
            }
        }
    }
    print_matrix(matrix, row, col);
    printf("\n");
    zero_out(matrix, row, col, zr, zc, len);
    print_matrix(matrix, row, col);
}
