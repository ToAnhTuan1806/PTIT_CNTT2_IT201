#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int maxSize;
}Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.data = (int *)malloc(sizeof(int)*maxSize);
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}
void printStack(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
}
int isFull(Stack s) {
    return s.top == s.maxSize - 1;
}
void push(Stack *s, int x) {
    if (isFull(*s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = x;
}
int main() {
    Stack s= createStack(5);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);

    printStack(s);
    free(s.data);

    return 0;
}
