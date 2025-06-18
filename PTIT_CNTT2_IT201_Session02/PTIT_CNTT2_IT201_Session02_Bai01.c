#include <stdio.h>

int main() {
    int n;
    printf("Nhap so ptu cua mang: ");
    scanf("%d", &n);
    if (n<=0 || n>100) {
        printf("phan tu khong hop le");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int maxNum= arr[0];
    for (int i=0; i<n; i++) {
        if (arr[i]>maxNum) {
            maxNum=arr[i];
        }
    }
    printf("phan tu lon nhat trong mang la: %d\n", maxNum);
    return 0;
}
