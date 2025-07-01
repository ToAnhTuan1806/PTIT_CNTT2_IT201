#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int nLeft= mid-left+1;
    int nRight= right-mid;

    int leftArr[nLeft], rightArr[nRight];
    for (int i=0; i<nLeft; i++) {
        leftArr[i] = arr[left+i];
    }
    for (int i=0; i<nRight; i++) {
        rightArr[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=left;
    while (i<nLeft && j<nRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k]=leftArr[i];
            i++;
        }else {
            arr[k]=rightArr[j];
            j++;
        }
        k++;
    }
    while (i<nLeft) {
        arr[k]=leftArr[i];
        i++;
        k++;
    }
    while (j<nRight) {
        arr[k]=rightArr[j];
        j++;
        k++;
    }
}
int mergeSort(int arr[], int left, int right) {
    if (left<right) {
        int mid= left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;

}