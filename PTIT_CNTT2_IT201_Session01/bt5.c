#include <stdio.h>
// sắp xếp nổi bọt
void sort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    int arr[n];
    printf("Cac phan tu cua mang:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("Mang sau sap xep:   ");
    for (int i=0; i<n; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}
// độ phức tạp là O(n^2) (th xấu nhất) vì cần duyệt nhiều lần tất cả ptu cần so sánh, đổi chỗ
// độ phức tạp là O(n) (th tốt nhất) vì mảng đã gần được sắp xếp khôg cần đổi chỗ, chỉ cần duyệt qua 1 lần