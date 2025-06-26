#include <stdio.h>

int sum(int arr[], int n) {
    //arr[3]={2,4,6}
    if (n==0) {
        return 0;
    }
    return arr[n-1]+sum(arr, n-1);
    //6+4+2
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int result = sum(arr, n);
    printf("%d", result);
    return 0;
}