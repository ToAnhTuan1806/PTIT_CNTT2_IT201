#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack (Stack *s) {
    s->top=-1;
}

int isFull(Stack *s) {
    return s->top==MAX-1;
}
int isEmpty(Stack *s) {
    return s->top==-1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++s->top] = c;
    }
}
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return 0;
}

int postfix(char expr[]) {
    Stack s;
    initStack(&s);
    for (int i=0; i<strlen(expr); i++) {
        char c=expr[i];
        if (isdigit(c)) {
            push(&s, c-'0');
        }else {
            int n2=pop(&s);
            int n1=pop(&s);
            int result=0;
            switch (c) {
                case '+':
                    result=n1+n2;
                    break;
                case '-':
                    result=n1-n2;
                    break;
                case '*':
                    result=n1*n2;
                    break;
                case '/':
                    result=n1/n2;
                    break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}



int main() {
    char expr[MAX];
    printf("Nhap bieu thuc hau to: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    int result=postfix(expr);
    printf("%d\n", result);
    return 0;
}