#include <stdio.h>
#define MAX 100
//trien khai ngan xep doi voi cau truc mang
//khai bao mang
int stack[MAX];
//khai bao dinh nghia bien top
int top = -1;
//ham ktra xem ngan xep co rong hay khog
int isEmpty() {
    if (top==-1) {
        return 1;
    }
    return 0;
}
//ham kiem tra xem ngan xep da day hay chua
int isFull() {
    if (top==MAX-1) {
        return 1;
    }
    return 0;
}

//ham de them phan tu vao trong ngan xep
void push(int x) {
    //khi them ptu vao trong ngan xep, phair kiem tra xem ngan xep da day chua
    if (isFull()) {
        return;
    }
    top+=1;
    stack[top]=x;
}
//ham lay ptu tren dinh ra
int pop() {
    if (isEmpty()) {
        return -1;
    }
    int temp=stack[top];
    top--;
    return temp;
}



int main() {
    int n=5; //them 5ptu vao trng ngan xep
    while (n--) {
        int t;
        scanf("%d", &t);
        push(t);
    }
    // in ra hien thi cac ptu trong ngan xep
    while (!isEmpty()) {
        printf("%d", pop());
    }
    return 0;
}