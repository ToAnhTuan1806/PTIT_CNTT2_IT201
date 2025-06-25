#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    int min=arr[0];
    int index=0;
    for (int i=1; i<n; i++) {
        if (arr[i]<min) {
            min=arr[i];
            index=i;
        }
    }
    printf("chi so phan tu nho nhat dau tien trong mang: %d\n", index);
    return 0;
}