#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node*front;
    Node*rear;
}Queue;

void initQueue(Queue*q) {
    q->front=NULL;
    q->rear=NULL;
}

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("khong the cap phat o nho");
        return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void enQueue(Queue*q, int value) {
    Node*newNode=createNode(value);
    if (q->rear==NULL) {
        q->front=newNode;
        q->rear=newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

void printQueue(Queue*q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("rear->%d->NULL\n", q->rear->data);
}

void deQueue(Queue*q) {
    printf("\n");
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node*temp=q->front;
    q->front=q->front->next;
    free(temp);

    if (q->front==NULL) {
        q->rear=NULL;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);

    int value;
    for (int i=0; i<n; i++) {
        printf("Nhap so nguyen: ");
        scanf("%d",&value);
        enQueue(&q,value);
    }
    printQueue(&q);

    deQueue(&q);
    printQueue(&q);
    return 0;
}