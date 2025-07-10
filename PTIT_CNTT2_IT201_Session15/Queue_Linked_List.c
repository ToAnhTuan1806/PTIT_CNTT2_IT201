#include <stdio.h>
#include <stdlib.h>


//thao tac voi hang doi su dung DSLK
//B1:
typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct {
    Node* front; // trỏ đến ptu đầu tiên của hàng đợi
    Node* rear; // tro den ptu cuoi cung
}Queue;

//B2: ban dau khong co phan tu nao thi front va rear deu la NULL
void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

//B3:
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}
// Ket qua tra ve cua ham neu la 1 tuc la khong co phan tu, khac 1 co phan tu

//B4:
void enQueue(Queue *queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat o nho");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    //neu hang doi khong co phan tu nao thi front va rear gan bang newNode
    if (isEmpty(queue)) {
        queue->front=newNode;
        queue->rear=newNode;
    }else {
        queue->rear->next=newNode;// lien ket voi node cuoi
        queue->rear=newNode;// cap nhat lai rear phan tu cuoi cung cua hang doi
    }
}

//B5: Xoa
int deQueue(Queue *queue) {
    //Ktra hang doi co phan tu hay khong
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return -1;
    }
    Node* temp=queue->front; // tao con tro, trop toi phan tu dau tien cua hang doi
    //de sau nay cac em free()
    int value=temp->data; // luu gia tri phan tu can xoa
    //cap nhat lai phan tu dau cua hang doi
    queue->front=queue->front->next;
    if (queue->front==NULL) {
        //khong con ptu nao trong hang doi thi phai gan gia tri rear ve NULL
        queue->rear=NULL;
    }
    //gai phong bo nho
    free(temp);
    return value;
}

//B6: Hien thi phan tu dau tien trong hang doi
int frontValue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return -1;
    }
    return queue->front->data;
}

//B7: Hien thi
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    Node *temp=queue->front;
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

//B8: Trien khai trong main
int main() {
    Queue q;
    initQueue(&q);
    enQueue(&q,1);
    enQueue(&q,2);
    enQueue(&q,3);
    enQueue(&q,4);
    enQueue(&q,5);
    printf("%d\n",deQueue(&q));
    printf("%d\n",frontValue(&q));
    displayQueue(&q);

    return 0;
}