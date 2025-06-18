#include <stdio.h>

int main() {
    int n;
    printf("nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>100) {
        printf("phan tu khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    //dao nguoc mang
    for (int i=0; i<n/2; i++) {
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }

    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}
