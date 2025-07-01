#include <stdio.h>

int  main() {
    int n;
    printf("Nhap so luog phan tu cua mang: ");
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

    int search;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &search);

    int check=0;
    int index=-1;
    for (int i=0; i<n; i++) {
        if (arr[i]==search) {
            check=1;
            index=i;
            break;
        }
    }
    for (int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (check) {
        printf("search = %d\n", search);
        printf("vi tri thu %d\n", index+1);
    }else {
        printf("search = %d\n", search);
        printf("khong ton tai phan tu");
    }


    return 0;
}