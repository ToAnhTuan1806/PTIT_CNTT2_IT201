#include<stdio.h>

#define MAX 100

int main() {
    int n,v;
    printf("nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    int edges[MAX][2];
    printf("nhap cac canh (u v):\n");
    for (int i=0; i<=n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int k;
    printf("nhap dinh muon kiem tra: ");
    scanf("%d", &k);

    int count=0;
    for (int i=0; i<v; i++) {
        if (edges[i][0]==k || edges[i][1]==k) {
            count++;
        }
    }
    printf("so dinh ke voi %d la: %d\n", k, count);
}