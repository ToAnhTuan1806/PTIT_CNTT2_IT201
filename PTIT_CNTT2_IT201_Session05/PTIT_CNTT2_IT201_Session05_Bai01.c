# include <stdio.h>

int printNumber(int n) {
    if (n==0) {
        return;
    }
    printNumber(n-1);
    printf("%d\n", n);
}


int main() {
    int n;
    printf("Nhap vao mot so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("so khong hop le");
    }else {
        printNumber(n);
        printf("\n");
    }
    return 0;
}