#include <stdio.h>

int countExist(int arr[], int size, int element) {
    int count=0;
    for (int i=0; i<size; i++) {
        if (arr[i]==element) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    int element;
    printf("Nhap so ptu cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>100) {
        printf("phan tu khong hop le\n");
        return 0;
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
    printf("Nhap mot so bat ky: ");
    scanf("%d", &element);

    int result= countExist(arr, n, element);
    // printf("So lan xuat hien cua ptu %d la: %d\n", element, result);
    printf("%d", result);
    return 0;
}