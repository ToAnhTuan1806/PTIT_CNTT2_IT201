#include <stdio.h>

int insertionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int key=arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n<=0 || n>1000) {
        printf("so luong phan tu khong hop le");
        return 0;
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;

}