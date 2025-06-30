#include <stdio.h>


int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n<=0||n>1000) {
        printf("So luong phan tu khong hop le");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int negative[n], zero[n], positive[n];
    int negCount=0, zeroCount=0, posCount=0;

    for (int i=0; i<n; i++) {
        if (arr[i]<0) {
            negative[negCount++]=arr[i];
        }else if (arr[i]==0) {
            zero[zeroCount++]=arr[i];
        }else {
            positive[posCount++]=arr[i];
        }
    }

    int sortArr[n];
    int index=0;

    for (int i=0; i<negCount; i++) {
        sortArr[index++]=negative[i];
    }

    for (int i=0; i<zeroCount; i++) {
        sortArr[index++]=zero[i];
    }

    for (int i=0; i<posCount; i++) {
        sortArr[index++]=positive[i];
    }

    printf("after: ");
    for (int i=0; i<n; i++) {
        printf("%d ", sortArr[i]);
    }


    return 0;
}