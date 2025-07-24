#include<stdio.h>

#define MAX 100

int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);

    int matrix[MAX][MAX];
    printf("nhap ma tran ke: \n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int count=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (matrix[i][j]==1) {
                count++;
            }
        }
    }

    printf("so canh: %d\n", count);
    return 0;
}