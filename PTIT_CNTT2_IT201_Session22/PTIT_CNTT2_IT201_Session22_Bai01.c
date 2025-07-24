#include<stdio.h>

#define MAX 100

int matrix[MAX][MAX];

void addEdge(int matrix[MAX][MAX], int u, int v) {
    matrix[u][v]=1;
    matrix[v][u]=1;
}

void printMatrix(int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, u ,v;
    printf("nhap so dinh: ");
    scanf("%d",&n);
    for (int i=0;i<=n;i++) {
        printf("nhap canh (u v):\n");
        scanf("%d %d",&u,&v);
        addEdge(matrix,u,v);
    }
    printMatrix(n);

    return 0;
}