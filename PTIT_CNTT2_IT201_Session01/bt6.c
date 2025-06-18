#include <stdio.h>

int countExist(int arr[], int size, int elementCheck) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i]==elementCheck) {
            count++;
        }
    }
    return count;
}
int main() {
    int n;
    int elementCheck;

    printf("Nhap so luong ptu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
    printf("Nhap ptu can ktra: ");
    scanf("%d", &elementCheck);
    int result = countExist(arr, n, elementCheck);
    printf("So lan xuat hien cua ptu %d la: %d\n", elementCheck, result);
    return 0;
}
// độ phức tạp là O(n) vì duyệt qua toàn bộ mảng một lần trong hàm countExist