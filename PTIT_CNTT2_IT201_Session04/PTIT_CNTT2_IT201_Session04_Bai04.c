# include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ",i);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value;
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &value);

    int index=-1;
    for (int i=n-1; i>=0; i--) {
        if (arr[i]==value) {
            index=i;
            break;
        }
    }
    if (index!=-1) {
        printf("%d\n", index);
    }else {
        printf("Khong tim thay phan tu");
    }

    return 0;
}
