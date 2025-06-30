#include <stdio.h>

int main() {
    int rows, cols;
    do {
        printf("Nhap so hang: ");
        scanf("%d", &rows);
    }while (rows<=0 || rows>1000);
    do {
        printf("Nhap so cot: ");
        scanf("%d", &cols);
    }while (cols<=0 || cols>1000);

    int arr[rows][cols];
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int k;
    do {
        printf("Nhap chi so cot k can sap xep: ");
        scanf("%d", &k);
    }while (k<0 || k>=cols);


    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (arr[j][k] > arr[j + 1][k]) {

                for (int col = 0; col < cols; col++) {
                    int temp = arr[j][col];
                    arr[j][col] = arr[j + 1][col];
                    arr[j + 1][col] = temp;
                }
            }
        }
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}