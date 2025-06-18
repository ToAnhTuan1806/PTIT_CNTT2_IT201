#include <stdio.h>

int main() {
    int n, pos;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>100) {
        printf("phan tu khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1 );
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    printf("Nhap vi tri muon xoa ptu: ");
    scanf("%d", &pos);
    if (pos<0 || pos>=n) {
        printf("vi tri khong hop le\n");
        return 1;
    }

    // xoa phan tu tai vi chi chi dinh
    for (int i=pos; i<n-1; i++) {
        arr[i]=arr[i+1];
    }
    n--;

    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;

}
