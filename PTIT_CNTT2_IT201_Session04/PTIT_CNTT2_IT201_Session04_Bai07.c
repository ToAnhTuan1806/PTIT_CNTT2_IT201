#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int check=0;
    //duyet nua dau mang de ss voi nua sau
    for (int i=0; i<n/2; i++) {
        // so sanh ptu dau vs ptu doi xung phia cuoi
        if (arr[i]==arr[n-i-1]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n-i-1]);
            check=1;
        }
    }

    if (check==0) {
        printf("Khong co phan tu doi xung\n");
    }
    return 0;
}