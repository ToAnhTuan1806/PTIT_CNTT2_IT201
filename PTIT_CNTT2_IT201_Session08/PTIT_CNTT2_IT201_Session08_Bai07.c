#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    for (int j=low; j<high; j++) {
        if (arr[j]<=pivot) {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
int quickSort(int arr[], int low, int high) {
    if (low<high) {
        int pivot=partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
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
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}