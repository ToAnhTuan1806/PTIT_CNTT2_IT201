// cai dat STACK bang mang
// tao mang data de chua cac phan tu Stack
// tao bien Top de luu phan tu tren cung cua ngan xep

#include <stdio.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
}Stack;
// Ham khoi tao Stack
void initStack(Stack*s) {
    // ban dau ngan xep rong, khong co phan tu thi gans gia tri top=-1
    s->top=-1;
}
// Ham kiem tra Stack da day chua chua
int isFull(Stack*s) {
    return s->top==MAX-1;
}
// Ham them phan tu
void push(Stack*s,int x) {
    //kiemtra xem Stack da day hay chua
    if (isFull(s)) {
        printf("Stack Overflow\n");
    }else {
        //them dc ptu va tang top len
        s->data[++s->top]=x;
    }
}
// hien thi phan tu
void printStack(Stack*s) {
    //hien thi danh sach cac ptu bat dau tu ptu dinh
    for (int i=s->top;i>=0;i--) {
        printf("%d ",s->data[i]);
    }
}
// Ham kiem tra ngan xep co phan tu hay khong
int isEmpty(Stack*s) {
    // neu =0 thi
    // neu =1 thi
    return s->top==-1; // ket qua ve cua ham 0||1
}

//TOP(): xem ptu o tren dinh
int top(Stack*s) {
    //ktra ngan xep cos ptu hay khong
    if (isEmpty(s)) {
        //mang khong co ptu nao
        return -1;
    }
    return s->data[s->top];
}
// Ham xoa phan tu trong stack
int pop(Stack*s) {
    // khi xoa can kiem tra ngan xep co ptu hay khong
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// Ham hioen thi trong ngan xep co bao nh ptu
int size(Stack*s) {
    return s->top+1;
}

int main () {
    Stack s;
    initStack(&s);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    // printStack(&s);
    // printf("%d\n",top(&s));
    pop(&s);
    printStack(&s);
    return 0;
}