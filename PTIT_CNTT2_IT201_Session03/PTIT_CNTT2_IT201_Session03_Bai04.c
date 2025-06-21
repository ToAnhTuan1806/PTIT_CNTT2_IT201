#include <stdio.h>
#include <stdlib.h>

#define MIN_INFINITY -10000
#define MAX_INFINITY 10000

int main() {
    int rows, cols;
    do {
        printf("Nhap vao so hang = ");
        scanf("%d", &rows);
        if (rows<0 || rows>100) {
            printf("khong hop le thu lai\n");
        }
    }while (rows<0 || rows>100);

    do {
        printf("Nhap vao so cot = ");
        scanf("%d", &cols);
        if (cols<0 || cols>100) {
            printf("khong hop le thu lai\n");
        }
    }while (cols<0 || cols>100);

    // cap phat dong mang 2 chieu
    int **matrix = malloc(rows*sizeof(int));
    for (int i=0; i<rows; i++) {
        matrix[i]=malloc(cols*sizeof(int));
    }

    // nhap du lieu
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("nhap arr[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // in ma tran
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }

    // thuc hien tim max va min trong matrix
    int min = MAX_INFINITY;
    int max= MIN_INFINITY;

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (max<matrix[i][j]) {
                max=matrix[i][j];
            }
            if (min>matrix[i][j]) {
                min=matrix[i][j];
            }
        }
    }
    printf("max = %d, min = %d\n", max, min);

    // giai phong bo nho
    for (int i=0; i<rows; i++) {
        free(matrix[i]);
    }
    free(matrix);


    return 0;
    }
