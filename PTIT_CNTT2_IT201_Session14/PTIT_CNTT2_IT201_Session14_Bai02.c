#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node*next;
}Node;

Node*createNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}
typedef struct {
    Node *head;
} Stack;
void initStack(Stack*s) {
    s->head=NULL;
}

void push(Stack*s,int x) {
    Node*node=createNode(x);
    node->next=s->head;
    s->head=node;
}

void printStack(Stack s) {
    Node*current=s.head;
    while(current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

int main() {
    Stack s;
    initStack(&s);

    int arr[]={5,4,3,2,1};
    for (int i=0; i<5; i++) {
        push(&s,arr[i]);
    }
    printStack(s);

    int x;
    printf("Nhap so ng duong bat ky: ");
    scanf("%d",&x);

    if (x>0) {
        push(&s,x);
    }else {
        printf("khong hop le\n");
    }
    printStack(s);

    return 0;
}