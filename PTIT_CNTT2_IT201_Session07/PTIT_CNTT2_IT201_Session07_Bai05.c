#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    for (int j=low; j<high; j++) {
        if (arr[j]<pivot) {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    // hoan doi ptu trung gian va pivot
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}

int quicksort(int arr[], int low, int high) {
    if (low<high) {
        int pivotIndex=partition(arr, low, high);
        quicksort(arr, low, pivotIndex-1);
        quicksort(arr, pivotIndex+1, high);
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n<=0 || n>1000) {
        printf("so luong phan tu khong hop le");
        return 1;
    }

    int arr[n];
    for (int i=0 ;i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    for (int i=0 ;i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n-1);
    printf("after: ");
    for (int i=0 ;i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}