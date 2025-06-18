#include <stdio.h>

int main() {
    int n, element;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d, ",arr[i]);
    }
    printf("\n");

    printf("Nhap mot so nguyen bat ky: ");
    scanf("%d", &element);

    // duyet cac cap ptu
    int check = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++ ) {
            if (arr[i]+arr[j]==element) {
                printf("%d, %d\n", arr[i], arr[j]);
                check = 1;
            }
        }
    }
    if (check==0) {
        printf("Khong tim thay");
    }
    return 0;
}