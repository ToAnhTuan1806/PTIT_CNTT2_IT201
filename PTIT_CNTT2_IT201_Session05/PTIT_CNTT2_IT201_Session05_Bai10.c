#include <stdio.h>

int recursion(int row, int col, int i, int j, int backedRow, int backedCol) {
    if (i==row-1 || j==col-1) {
        return 1;
    }
    if (i>row-1 || j>col-1) {
        return 0;
    }
    if (backedCol==j && backedRow==i) {
        return 0;
    }
    return recursion(row, col, i+1, j, backedRow, backedCol)+ recursion(row, col, i, j+1, backedRow, backedCol);
}

int main() {
    int row;
    int col;
    int backedRow;
    int backedCol;
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    printf("Nhap hang bi chan: ");
    scanf("%d", &backedRow);
    printf("Nhat cot bi chan: ");
    scanf("%d", &backedCol);
    int result=recursion(row, col, 0, 0, backedRow, backedCol);
    printf("%d", result);

    return 0;
}