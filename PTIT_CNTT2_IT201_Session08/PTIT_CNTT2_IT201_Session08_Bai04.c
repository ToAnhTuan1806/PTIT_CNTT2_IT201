#include <stdio.h>

int selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex=i;
        for (int j=i+1; j<n;j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
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

    selectionSort(arr, n);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}