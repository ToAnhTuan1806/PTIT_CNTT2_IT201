#include <stdio.h>

int sum(int firstNum, int secondNum) {
    if (firstNum>secondNum) {
        return 0;
    }
    else {
        return firstNum+sum(firstNum+1, secondNum);
    }
}

int main() {
    int firstNum;
    int secondNum;
    printf("Nhap so bat dau: ");
    scanf("%d", &firstNum);
    printf("Nhap so ket thuc: ");
    scanf("%d", &secondNum);
    if (firstNum<0 || secondNum <0) {
        printf("Loi");
        return 1;
    }
    int result = sum(firstNum, secondNum);
    printf("%d", result);
    return 0;
}