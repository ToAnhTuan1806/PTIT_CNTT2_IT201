#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    //sap xep mang
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value;
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &value);

    int index=-1;
    int left=0, right=n-1;
    while (left<=right) {
        int mid=(left+right)/2;
        if (arr[mid]==value) {
            index=mid;
            break;
        }else if (arr[mid]<value) {
            left=mid+1;
        }else {
            right=mid-1;
        }
    }

    if (index!=-1) {
        printf("Phan tu co trong mang");
    } else {
        printf("Phan tu khong co trong mang");
    }
    return 0;
}