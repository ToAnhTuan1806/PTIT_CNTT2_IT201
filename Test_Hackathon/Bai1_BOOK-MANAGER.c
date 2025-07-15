#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char title[100];
    char author[100];
    char category[50];
    float price;
}Book;

//Ds quan ly sach
typedef struct SNode {
    Book book;
    struct SNode*next;
}SNode;
//Ds quan ly sach da doc
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
        if (temp->book.id==id) {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//Them sach moi
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

    printf("Nhap ten sach moi: ");
    fgets(newNode->book.title, sizeof(newNode->book.title), stdin);
    newNode->book.title[strcspn(newNode->book.title, "\n")]='\0';

    printf("Nhap ten tac gia: ");
    fgets(newNode->book.author, sizeof(newNode->book.author), stdin);
    newNode->book.author[strcspn(newNode->book.author, "\n")]='\0';

    printf("Nhap the loai sach: ");
    fgets(newNode->book.category, sizeof(newNode->book.category), stdin);
    newNode->book.category[strcspn(newNode->book.category, "\n")]='\0';

    printf("Nhap gia sach: ");
    scanf("%f", &newNode->book.price);

    newNode->next=head;
    head=newNode;
    printf("Them sach moi thanh cong!\n");
}

//Hien thi sach
void displayBook() {
    SNode*temp=head;
    if (!temp) {
        printf("Danh sach quan ly sach trong\n");
        return;
    }
    printf("Danh sach sach:\n");
    while (temp) {
        printf("Ma sach: %d | Ten sach: %s | Tac gia: %s | The loai: %s | Gia sach: %.2f\n",
            temp->book.id, temp->book.title, temp->book.author, temp->book.category, temp->book.price);
        temp=temp->next;
    }
}

//Xoa sach
void deleteBook() {
    int id;
    printf("Nhap ma sach muon xoa: ");
    scanf("%d", &id);
    SNode*temp=head;
    SNode*prev=NULL;
    while (temp!=NULL && temp->book.id!=id) {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong tim thay sach\n");
        return;
    }
    if (prev==NULL) {
        head=temp->next;
    }else {
        prev->next=temp->next;
    }
    free(temp);
    printf("Da xoa sach voi ma %d\n", id);
}

//Cap nhat thong tin sach
void updateBook() {
    int id;
    printf("Nhap ma sach muon cap nhat: ");
    scanf("%d", &id);
    getchar();
    SNode*temp=head;
    while (temp!=NULL && temp->book.id!=id) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong tim thay sach\n");
        return;
    }

    printf("Nhap ten sach: ");
    fgets(temp->book.title, sizeof(temp->book.title), stdin);
    temp->book.title[strcspn(temp->book.title, "\n")]='\0';

    printf("Nhap ten tac gia: ");
    fgets(temp->book.author, sizeof(temp->book.author), stdin);
    temp->book.author[strcspn(temp->book.author, "\n")]='\0';

    printf("Nhap the loai: ");
    fgets(temp->book.category, sizeof(temp->book.category), stdin);
    temp->book.category[strcspn(temp->book.category, "\n")]='\0';

    printf("Nhap gia sach: ");
    scanf("%f", &temp->book.price);
    getchar();

    printf("Cap nhat thong tin sach thanh cong\n");
}

//Danh dau sach da doc xong
void markCompleted() {
    int id;
    printf("Nhap ma sach can danh dau hoan thanh: ");
    scanf("%d", &id);
    getchar();

    SNode*temp=head;
    SNode*prev=NULL;
    while (temp!=NULL && temp->book.id!=id) {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong tim thay sach\n");
        return;
    }

    DNode*newNode=(DNode*)malloc(sizeof(DNode));
    newNode->book=temp->book;
    newNode->prev=NULL;
    newNode->next=completedBook;
    if (completedBook!=NULL) {
        completedBook->prev=newNode;
    }
    completedBook=newNode;

    //xoa khoi dslk don
    if (prev==NULL) {
        head=temp->next;
    }else {
        prev->next=temp->next;
    }
    free(temp);
    printf("Da danh dau hoan thanh\n");
}

//Sap xep sach theo gia tang dan
void sortBooksByPrice() {
    if (head==NULL || head->next==NULL) {
        printf("Danh sach rong\n");
        return;
    }
    SNode *i,*j;
    for (i=head; i!=NULL; i=i->next) {
        for (j=i->next; j!=NULL; j=j->next) {
            if (i->book.price > j->book.price) {
                Book temp=i->book;
                i->book=j->book;
                j->book=temp;
            }
        }
    }
    printf("Da sap xep sach theo gia tang dan\n");
}

//Tim kiem sach theo tieu de
void searchBookByTitle() {
    
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