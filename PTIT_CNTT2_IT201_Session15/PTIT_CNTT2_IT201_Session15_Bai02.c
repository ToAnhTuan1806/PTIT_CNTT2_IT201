#include <stdio.h>

#define MAX 5

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

void enQueue(Queue *q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int main() {
    Queue q;
    initQueue(&q);

    int n;
    printf("Nhap so phan tu muon them: ");
    scanf("%d", &n);

    if (n>MAX) {
        printf("Queue is full\n");
        n=MAX;
    }


    int value;
    for (int i=0; i<n; i++) {
        printf("ptu thu %d: ", i+1);
        scanf("%d", &value);
        enQueue(&q, value);
    }

    printQueue(q);



    return 0;
}
