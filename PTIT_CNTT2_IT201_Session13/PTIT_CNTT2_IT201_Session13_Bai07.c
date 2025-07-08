#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
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
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

int validate(char expr[]) {
    Stack s;
    initStack(&s);
    for (int i=0; i<strlen(expr); i++) {
        char c = expr[i];
        //ngoac mo
        if (c=='(' || c=='[' || c=='{') {
            push(&s, c);
        }
        //ngoac dong ktra voi dinh
        else if (c==')' || c==']' || c=='}') {
            if (isEmpty(&s)) {
                return 0;
            }
            char top=pop(&s);
            if ((c==')' && top!='(' || c==']'&& top!='[' || c=='}'&& top=='{')) {
                return 0;
            }
        }
    }
    if (!isEmpty(&s)) {
        return 0;
    }
    return 1;
}



int main() {
    char expr[MAX];
    printf("Nhap bieu thuc bat ky: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (validate(expr)) {
        printf("TRUE\n");
    }else {
        printf("FALSE\n");
    }
    return 0;
}