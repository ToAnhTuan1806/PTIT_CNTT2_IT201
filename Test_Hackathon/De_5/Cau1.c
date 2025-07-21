#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    char category [50];
    float price;
} Book;

typedef struct SNode {
    Book book;
    struct SNode *next;
} SNode;

typedef struct DNode {
    Book book;
    struct DNode *prev;
    struct DNode *next;
}DNode;

SNode*head=NULL;
DNode* completedBook=NULL;

int checkID(int id) {
    SNode*temp=head;
    while (temp!=NULL) {
        if (temp->book.id == id) {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void addBook() {
    SNode*newNode=(SNode*)malloc(sizeof(SNode));
    if (newNode==NULL) {
        printf("Cap phat bo nho khong thanh cong\n");
        return;
    }
    do {
        printf("Nhap ma sach: ");
        scanf("%d", &newNode->book.id);
        if (checkID(newNode->book.id)) {
            printf("Ma sach da ton tai. Vui long nhap lai!\n");
        }
    }while (checkID(newNode->book.id));
    getchar();
}




int main() {
    int choice;
    do {
        printf("\n ===== BOOK  MANAGER =====\n");
        printf("1. Them sach\n");
        printf("2. Hien thi danh sach tat ca quyen sach\n");
        printf("3. Xoa sach\n");
        printf("4. Cap nhat thong tin\n");
        printf("5. Danh dau sach da doc xong\n");
        printf("6. Sap xep sach theo gia tang dan\n");
        printf("7. Tim kiem sach theo tieu de\n");
        printf("8. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                markCompleted();
                break;
            case 6:
                sortBooksByPrice();
                break;
            case 7:

                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai\n");
        }
    }while (choice != 8);


    return 0;
}