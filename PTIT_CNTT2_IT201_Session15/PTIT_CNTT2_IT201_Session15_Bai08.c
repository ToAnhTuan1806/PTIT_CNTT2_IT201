#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
}Customer;
typedef struct {
    Customer data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue *q) {
    q->front=0;
    q->rear=-1;
}
int isEmpty(Queue *q) {
    return q->rear<q->front;
}
int isFull(Queue *q) {
    return q->rear-q->front+1==MAX;
}

//ham them khach
void enQueue(Queue *q, Customer c) {
    if (isFull(q)) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    q->data[q->rear]=c;
}

//ham phuc vu khach hang
void deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    Customer c=q->data[q->front];
    printf("Dang phuc vu :%s, %d tuoi\n", c.name, c.age);

    q->front++;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    for (int i=q->front; i<=q->rear; i++) {
        printf(" - %s, %d tuoi\n",q->data[i].name, q->data[i].age);
    }
}

int main() {
    Queue qOld, qNormal;
    initQueue(&qOld);
    initQueue(&qNormal);

    int choice;
    Customer c;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Them khach hang moi\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach dang cho\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(c.name, NAME_LENGTH, stdin);
                c.name[strcspn(c.name, "\n")] = 0;
                printf("Nhap tuoi khach hang: ");
                scanf("%d", &c.age);
                getchar();
                if (c.age>=60) {
                    enQueue(&qOld, c);
                    printf("Da them vao hang doi uu tien\n");
                }else {
                    enQueue(&qNormal, c);
                    printf("Da them vao hang doi thuong\n");
                }
                break;
            case 2:
                if (!isEmpty(&qOld)) {
                    deQueue(&qOld);
                }else if (!isEmpty(&qNormal)) {
                    deQueue(&qNormal);
                }else {
                    printf("Khong co khach hang nao trong hang doi\n");
                }
                break;
            case 3:
                printf("Danh sach uu tien:\n");
                displayQueue(&qOld);
                printf("Danh sach binh thuong:\n");
                displayQueue(&qNormal);
                break;
            case 4:
                printf("Thoat thanh cong!\n");
                break;
            default:
                printf("Lua chon khong hop le thu lai \n: ");
        }
    }while(choice!=4);

    return 0;
}