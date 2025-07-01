#include <stdio.h>

void swap(int arr[][1000], int row1, int row2, int cols) {
    for (int i=0; i<cols;i++) {
        int temp=arr[row1][i];
        arr[row1][i]=arr[row2][i];
        arr[row2][i]=temp;
    }
}
void sort(int arr[][1000], int rows, int cols, int k) {
    for (int i=0; i<rows-1; i++) {
        for (int j=0; j<rows-i-1;j++) {
            if (arr[j][k]>arr[j+1][k]) {
                swap(arr, j, j+1, cols);
            }
        }
    }
}

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

    sort(arr, rows, cols, k);

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

