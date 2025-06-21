#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<0) {
        printf("so luong khong hop le\n");
        return 1;
    }

    arr=(int*)malloc(n*sizeof(int));

    //  nhap gia tri
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d", i+1);
        scanf("%d", &arr[i]);
    }
    // in ra mang
    for (int i=0; i<n; i++) {
        printf(" arr[%d] = %d", i, arr[i]);
    }

    //tim so co so luong xuat hien nhieu nhat
    int maxCount=0;
    int maxNumber;
    for (int i=0; i<n; i++) {
        int count=0;
        for (int j=i+1; j<n; j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }
        if (maxCount<count) {
            maxCount=count;
            maxNumber=arr[i];
        }
    }
    printf(" maxCount = %d", maxCount);


    free(arr);
    return 0;
}
