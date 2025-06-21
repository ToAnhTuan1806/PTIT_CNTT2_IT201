#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    while (1) {
        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &n);

        if (n<=0 || n>=1000) {
            printf("so luong phan tu khong hop le\n");
        } else {
            break;
        }
    }
    int *arr=(int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("khong cap paht duoc bo nho\n");
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

    int max=arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    printf("max=%d\n", max);
    free(arr);
    return 0;
}
