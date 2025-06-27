#include <stdio.h>

int fibonacci(int n) {
    //1. dieu kien dung
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    // 2. goi lai ham
    return fibonacci(n-1)+fibonacci(n-2);

}
int main() {
    int n;
    printf("Nhap n so dau tien: ");
    scanf("%d",&n);
    for (int i=n-1; i>=0; i--) {
        printf("%d ", fibonacci(i));
    }
}