#include <stdio.h>
#include <stdlib.h>


int tongDuongCheoChinh(int **arr, int n) {
    int total = 0;
    for (int i=0; i<n ;i++) {
        total+= arr[i][i];
    }
    return total;
}
int tongDuongCheoPhu(int **arr, int n) {
    int total = 0;
    for (int i=0; i<n; i++) {
        total+= arr[i][n-i-1];
    }
    return total;
}

int main() {
    int rows, cols;
    do {
        printf("Nhap vao so hang = ");
        scanf("%d", &rows);
        if (rows<=0 || rows>=1000) {
            printf("khong hop le thu lai\n");
        }
    }while (rows<=0 || rows>=1000);

    do {
        printf("Nhap vao so cot = ");
        scanf("%d", &cols);
        if (cols<=0 || cols>=1000) {
            printf("khong hop le thu lai\n");
        }
    }while (cols<=0 || cols>=1000);

    // cap phat dong mang 2 chieu
    int **matrix = malloc(rows*sizeof(int*));
    for (int i=0; i<rows; i++) {
        matrix[i]=malloc(cols*sizeof(int));
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("nhap arr[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (rows==cols) {
        int result1 = tongDuongCheoChinh(matrix, rows);
        int result2 = tongDuongCheoPhu(matrix, rows);

        printf("Tong duong cheo chinh =  %d\n", result1);
        printf("Tong duong cheo phu =  %d\n", result2);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }

    for (int i=0; i<rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}