#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int cap;
}Stack;

Stack createStack(int cap) {
    Stack s;
    s.data = (int *)malloc(sizeof(int)*cap);
    s.top = -1;
    s.cap = cap;
    return s;
}
int isFull(Stack s) {
    return s.top == s.cap - 1;
}
int isEmpty(Stack s) {
    return s.top == -1;
}
void push(Stack *s, int x) {
    if (isFull(*s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = x;
}
int pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("No element in stack\n");
        return -1;
    }
    return s->data[s->top--];
}

void printStack(Stack s) {
    for (int i=0; i<=s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
    printf("top: %d\n", s.top);
    printf("cap: %d\n", s.cap);
}
int main() {
    Stack s= createStack(5);
    int x;
    printf("Nhap cac ptu:\n");
    for (int i=0; i<5; i++) {
        scanf("%d", &x);
        push(&s, x);
    }
    printStack(s);

    int popValue=pop(&s);
    if (popValue!=-1) {
        printf("%d\n", popValue);
    }
    while (!isEmpty(s)) {
        pop(&s);
    }
    printStack(s);
    pop(&s);
    free(s.data);

    return 0;
}
