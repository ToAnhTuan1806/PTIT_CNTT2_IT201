#include <stdio.h>

int totalNum(int n) {
    if (n==0) {
        return 0;
    }
    return (n%10)+totalNum(n/10);
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("khong hop le");
        return 1;
    }
    int result=totalNum(n);
    printf("%d", result);

    return 0;
}