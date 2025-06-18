#include <stdio.h>
//cach 1: dung cthuc tinh tong
int sum(int n) {
    return n *(n+1)/2;
}

//cach 2: dung vong lap cong don
int sumLoop(int n) {
    int total = 0;
    for (int i=0; i<=n; i++) {
        total+= i;
    }
    return total;
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    int toatalN1 = sum(n);
    printf("Tong theo cach 1: %d\n", toatalN1);
// cach 1: độ phức tạp là O(1) vì không phụ thuộc vào kích thước đâu vào
    int toatalN2 = sumLoop(n);
    printf("Tong theo cach 2: %d\n", toatalN2);
}
// cach 2: độ phức tạp là O(1) vì không phụ thuộc vào kích thước đâu vào