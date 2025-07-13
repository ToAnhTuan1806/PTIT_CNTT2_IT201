#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node* front;
    Node* rear;
}Queue;

void initQueue(Queue *q) {
    q->front=NULL;
    q->rear=NULL;
}

int isEmpty(Queue *q) {
    return q->front==NULL;
}

int main() {
    Queue q;
    initQueue(&q);
    if (isEmpty(&q)) {
        printf("Hang doi rong\n");
    }else {
        printf("Hang doi khog rong");
    }
    return 0;
}