#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100
#define NAME_LENGTH 50

typedef struct {
    char data[MAX][NAME_LENGTH];
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

//ham them khach moi
void enQueue(Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    strcpy(q->data[q->rear],name);
    printf("Da them '%s vao hang doi\n", name);
}

//ham phuc vu khach hang
void deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Dang phuc vu :%s\n", q->data[q->front]);
    q->front++;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("danh sach khach hang dang cho:\n");
    for (int i=q->front; i<=q->rear; i++) {
        printf(" - %s\n",q->data[i]);
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    char name[NAME_LENGTH];
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
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                enQueue(&q, name);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                displayQueue(&q);
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