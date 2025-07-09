#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node*createNode(int data) {
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

typedef struct {
    Node*top;
} Stack;
void initStack(Stack*s) {
    s->top=NULL;
}

int main() {
    Stack s;
    initStack(&s);

    if (s.top==NULL) {
        printf("in thanh cong\n");
    }else {
        printf("false\n");
    }
    return 0;
}