#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int flag=0;

    while(flag==0) {
        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &n);
        if (n<0) {
            printf("so luong phan tu khong am\n");
        } else if (n>1000) {
            printf("so luong phan tu phai lon hon 0\n");
        } else {
            flag=1;
        }
    }
    // cap phat bo nho dong
    int *arr=(int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("khong cap phat duoc bo nho\n");
        return 1;
    }

    for (int i=0; i<n; i++) {
        printf("So thu %d = ", i+1);
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
