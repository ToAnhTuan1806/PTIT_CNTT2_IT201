#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>100) {
        printf("phan tu khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    int pos, val;
    printf("Nhap vi tri muon sua: ");
    scanf("%d", &pos);
    if (pos<0 || pos >=n) {
        printf("vi tri khong hop le\n");
        return 1;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &val);

    arr[pos]=val;

    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}
