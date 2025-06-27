#include <stdio.h>

int changeToBinary(int n) {
    if (n==0) {
        return;
    }
    changeToBinary(n/2);
    printf("%d", n%2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &n);

        changeToBinary(n);
    return 0;
}
