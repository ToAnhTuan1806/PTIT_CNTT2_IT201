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
    Node*temp=q->front;
    printf("front->");
    if (temp==NULL) {
        printf("NULL\n");
    }else {
        while (temp!=NULL) {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
    printf("rear->");
    if (q->rear==NULL) {
        printf("NULL\n");
    }else {
        printf("%d->NULL\n",q->rear->data);
    }
}

int peek(Queue*q) {
    printf("\n");
    if (q->front==NULL) {
        printf("empty queue\n");
        return -1;
    }else {
        printf("%d\n",q->front->data);
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

    peek(&q);
    return 0;
}