#include <stdio.h>

int merge(int arr[], int left, int mid, int right) {
    int nLeft= mid-left+1; //pt mang trai
    int nRight= right-mid; //pt mang phai

    int L[nLeft], R[nRight];
    //sao chep du lieu vao mang tam
    for (int i=0; i<nLeft; i++) {
        L[i] = arr[left+i];
    }
    for (int i=0; i<nRight; i++) {
        R[i] = arr[mid+1+i];
    }

    //gop 2 mang con
    int i=0, j=0, k=left;
    while (i<nLeft && j<nRight) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }else {
            arr[k++] = R[j++];
        }
    }
    while (i<nLeft) {
        arr[k++] = L[i++];
    }
    while (j<nRight) {
        arr[k++] = R[j++];
    }
}
int mergeSort(int arr[], int left, int right) {
    if (left<right) {
        int mid =left+ (right-left)/2;
        mergeSort(arr, left, mid);// sx nua trai
        mergeSort(arr, mid+1, right);// sx nua phai
        merge(arr, left, mid, right);// gop
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

    mergeSort(arr, 0, n-1);
    printf("after: ");
    for (int i=0 ;i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}