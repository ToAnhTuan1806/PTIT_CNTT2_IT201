#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int maxSize;
}Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->maxSize=MAX;
}

void printQueue(Queue q) {
    if (q.rear<q.front) {
        printf("Hang doi rong\n");
    }else {
        for (int i=q.front; i<=q.rear; i++) {
            printf("%d ",q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    printf("Hang doi vua khoi tao:\n");
    printQueue(q);

    return 0;
}