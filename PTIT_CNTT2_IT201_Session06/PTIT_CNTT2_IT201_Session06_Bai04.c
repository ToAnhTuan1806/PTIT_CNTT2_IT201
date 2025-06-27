#include <stdio.h>

int tower(int n, char start, char mid, char end) {
    if (n==1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", start, end);
        return;
    }
    //1. di chuyen n-1 dia tu cot dau sang cot giua
    tower(n-1, start, end, mid);
    //2. chuyen dia con lai sang cot cuoi
    printf("Dia %d di chuyen tu %c sang %c\n", n, start, end);
    //3. chuyen n-1 dia tu cot giua sang cot dich
    tower(n-1, mid, start, end);
}

int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);
    if (n==0) {
        printf("input khong hop le");
        return 1;
    }

    tower(n, 'A', 'B', 'C');
    return 0;
}