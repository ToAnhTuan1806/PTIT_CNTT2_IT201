#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void inttStack (Stack *s) {
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

int symmetryStr(char str[]) {
    Stack s;
    inttStack(&s);

    int length = strlen(str);
    for (int i=0; i<length; i++) {
        push(&s, str[i]);
    }
    for (int i=0; i<length; i++) {
        if (str[i]!=pop(&s)) {
            return 0;
        }
    }
    return 1;
}




int main() {
    char str[MAX];
    printf("Nhap chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (symmetryStr(str)) {
        printf("TRUE\n");
    }else {
        printf("FALSE\n");
    }
    return 0;
}