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
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max=arr[0];
    int index=0;
    for (int i=1; i<n; i++) {
        if (arr[i]>max) {
            max=arr[i];
            index=i;
        }
    }
    printf("Chi so phan tu lon nhat dau tien trong mang: %d\n", index);


    return 0;
}