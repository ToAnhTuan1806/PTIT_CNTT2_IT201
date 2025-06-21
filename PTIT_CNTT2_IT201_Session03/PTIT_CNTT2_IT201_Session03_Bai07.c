#include <stdio.h>
#include <stdlib.h>

int tinhTongK(int **arr, int cols, int k){
int total=0;
for (int j=0; j<cols; j++) {
    total+=arr[k][j];
}
    return total;
}


int main() {
    int rows, cols;
    do {
        printf("nhap so hang: ");
        scanf("%d", &rows);
        if (rows<=0 || rows>=1000) {
            printf("So hang khong hop le\n");
        }
    }while (rows<=0 || rows>=1000);

    do {
        printf("nhap so cot: ");
        scanf("%d", &cols);
        if (cols<=0 || cols>=1000) {
            printf("So cot khong hop le\n");
        }
    }while (cols<=0 || cols>=1000);

    // cap phat dong mang 2 chieu
    int **matrix = malloc(rows*sizeof(int*));
    for (int i=0; i<rows; i++) {
        matrix[i]=malloc(cols*sizeof(int));
    }

    // nhap ptu cua mang
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // nhap k
    int k;
    printf("nhap so dong k can tinh tong: ");
    scanf("%d", &k);
    if (k<0||k>=rows) {
        printf("Hang can tinh khong ton tai\n");
    } else {
        int sum=tinhTongK(matrix, cols, k);
        printf("sum = %d\n", sum);
    }

    for (int i=0; i<rows; i++) {
        free(matrix[i]);
    }
    free(matrix);


    return 0;
}