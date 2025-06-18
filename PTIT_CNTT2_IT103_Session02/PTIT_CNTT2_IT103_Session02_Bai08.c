#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<n-1; i++) {
        int check = 1;
        for (int j=i+1; j<n; j++) {
            if (arr[i]<=arr[j]) {
                check = 0;
                break;
            }
        }
        if (check){
            printf("%d ", arr[i]);
        }
    }
    // in ptu cuoi cung
    if (n>0) {
        printf("%d", arr[n-1]);
    }
    return 0;
}