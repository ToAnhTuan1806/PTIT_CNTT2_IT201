#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sum(int n) {
    if (n<=0) {
        return 0;
    }
    else {
        return n+sum(n-1);
    }
}


int main() {
    int n;
    printf("Nhap so bat ki: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("khong hop le");
    }
    int result = sum(n);
    printf("%d", result);


    return 0;
}