#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    while (left<=right) {
        int mid=left+(right-left)/2;
        if (arr[mid]==x) {
            return mid;
        }else if (arr[mid]<x) {
            left=mid+1;
        }else {
            right=mid-1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n<=0 || n>1000) {
        printf("khong hop le");
        return 0;
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    //sx mang
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    int search;
    printf("nhap phan tu can tim: ");
    scanf("%d", &search);

    int index=binarySearch(arr, 0, n-1, search);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    if (index!=-1) {
        printf("phan tu o vi tri thu %d", index+1);
    }else {
        printf("khong ton tai phan tu");
    }

    return 0;
}