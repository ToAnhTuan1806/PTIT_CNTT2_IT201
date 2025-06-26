#include <stdio.h>

int factorial(int n) {
    if (n==0) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}

int main() {
    int n;
    printf("Nhap mot so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("so khong hop le");
    }else {
        int result=factorial(n);
        printf("%d", result);
    }
}