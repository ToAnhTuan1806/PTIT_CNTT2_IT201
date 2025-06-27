#include <stdio.h>

int recursion(int row, int col, int i, int j) {
    if (i==row-1 || j==col-1) {
        return 1;
    }
    if (i>row-1 || j>col-1) {
        return 0;
    }
    return recursion(row, col, i+1, j)+ recursion(row, col, i, j+1);
}

int main() {
    int row;
    int col;
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    int result=recursion(row, col, 0, 0);
    printf("%d", result);

    return 0;
}