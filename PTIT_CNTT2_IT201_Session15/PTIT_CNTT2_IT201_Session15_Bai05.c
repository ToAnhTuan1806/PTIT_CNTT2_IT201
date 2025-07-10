#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->capacity = MAX;
}

void printQueue(Queue q) {
    if (q.rear < q.front) {
        printf("Hang doi rong\n");
    } else {
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.data[i]);
        }
        printf("\n");
    }
    printf("front = %d,\n", q.front);
    printf("rear = %d,\n", q.rear);
    printf("capacity = %d\n", q.capacity);
}

int isEmpty(Queue q) {
    return q.rear<q.front;
}

void enQueue(Queue *q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

void viewQueue(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }else {
        for (int i=q.front; i<=q.rear; i++) {
            printf("%d\n", q.data[i]);
        }
    }
}

int deQueue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
        return -1;
    }else {
        int value = q->data[q->front];
        q->front++;
        return value;
    }
}

int main() {
    Queue q;
    initQueue(&q);


    deQueue(&q);
    printQueue(q);

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 5);

    int remove= deQueue(&q);
    printf("\n");
    printf("return value = %d\n", remove);
    printQueue(q);



    return 0;
}
