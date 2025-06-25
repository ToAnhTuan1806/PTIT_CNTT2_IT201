#include <stdio.h>

// tim kiem nhi phan bang de quy
int binanySearch(int arr[], int low, int high, int search) {
    if (low <= high) {
        int mid = (low+high)/2;
        if (search==arr[mid]) {
            return mid;
        } else if (search<arr[mid]) {
            return binanySearch(arr, low, mid-1, search);
        }else {
            return binanySearch(arr, mid+1, high, search);
        }
    } else {
        return -1;
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    //sap xep mang tang dan
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //in mang
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value;
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &value);

    int result=binanySearch(arr, 0, n-1, value);
    if (result!=-1) {
        printf("Phan tu co trong mang");
    }else {
        printf("Phan tu khong co trong mang");
    }

    return 0;

}