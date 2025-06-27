#include <stdio.h>

int countWays(int n) {
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    return countWays(n-1) + countWays(n-2);
}

int main() {
    int n;
    printf("Nhap so bac cua cau thang: ");
    scanf("%d", &n);

    if (n<=0) {
        printf("khong hop le");
        return 1;
    }
    int result = countWays(n);
    printf("%d", result);
    return 0;
}