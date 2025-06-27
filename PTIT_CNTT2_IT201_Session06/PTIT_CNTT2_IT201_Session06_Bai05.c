#include <stdio.h>

int findMax(int arr[], int n, int index) {
    // 1.dk dung
    if (index==n-1) {
        return arr[index];
    }
    int max=findMax(arr, n, index+1);
    //2. goi ham
    return arr[index]>max?arr[index]:max;
}
int findMin(int arr[], int n, int index) {
    // 1.dk dung
    if (index==n-1) {
        return arr[index];
    }
    int min=findMin(arr, n, index+1);
    //2. goi ham
    return arr[index]<min?arr[index]:min;
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max = findMax(arr, n, 0);
    int min = findMin(arr, n, 0);
    printf("max = %d, min = %d\n", max, min);
    return 0;
}
