#include <stdio.h>
    void printDouble(int n){
        int i=1;
        while (i<n) {
            printf("%d\n", i);
                i*=2;
        }
    }
// bắt đầu từ 1 , in giá trị của i và nhân đôi chạy đến khi i>=n
int main() {
        int n=10;
        printDouble(n);
        return 0;
    }
// Độ phức tạp: O(log n)