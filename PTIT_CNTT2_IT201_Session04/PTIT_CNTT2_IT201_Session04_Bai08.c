#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value;
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &value);

    int check=0; // bien co de ktra co thay khong
    for (int i=0; i<n; i++) {
        if (arr[i]==value) {
            printf("%d, ", i);
            check=1;// danh dau tim thay
        }
    }
    if (check==0) {
        printf("Phan tu khong co trong mang");
    }

    return 0;
}