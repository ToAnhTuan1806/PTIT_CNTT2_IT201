#include<stdio.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top==MAX-1;
}
int isEmpty(Stack *s) {
    return s->top==-1;
}
void push (Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = x;
}
void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int pop (Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}

void reverse(int arr[], int n) {
    Stack s;
    initStack(&s);
    //day ptu vao stack
    for (int i=0; i<n; i++) {
        push(&s, arr[i]);
    }
    //lay ptu  khoi stack va sap xep
    for (int i=0; i<n; i++) {
        arr[i] = pop(&s);
    }
}



int main() {
    int n;
    printf("Nhap so ptu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    reverse(arr, n);
    printArray(arr, n);

    return 0;
}