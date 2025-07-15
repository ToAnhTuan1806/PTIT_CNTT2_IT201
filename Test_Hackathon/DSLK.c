#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char title[100];
    int credit;
}Course;

//khoa hoc dang hoc
typedef struct SNode {
    Course course;
    struct SNode *next;
}SNode;
//khoa hoc da hoan thanh
typedef struct DNode {
    Course course;
    struct DNode *prev;
    struct DNode *next;
}DNode;

SNode* head=NULL;
DNode* completedCourses=NULL;

int checkID(int id) {
    SNode*temp=head;
    while (temp!=NULL) {
        if (temp->course.id == id) {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void addCourse() {
    SNode* newNode=(SNode*)malloc(sizeof(SNode));
    if (newNode==NULL) {
        printf("Cap phat bo nho khong thanh cong");
        return;
    }
    do {
        printf("Nhap ID khoa hoc: ");
        scanf("%d", &newNode->course.id);
        if (checkID(newNode->course.id)) {
            printf("ID da ton tai. Vui long nhap lai!");
        }
    } while (checkID(newNode->course.id));

    printf("Nhap ten khoa hoc: ");
    getchar();
    fgets(newNode->course.title,sizeof(newNode->course.title),stdin);
    newNode->course.title[strcspn(newNode->course.title,"\n")]='\0';
    printf("Nhap so tin chi: ");
    scanf("%d", &newNode->course.credit);

    newNode->next=head;
    head=newNode;
    printf("them khoa hoc thanh cong \n");

}

void displayCourse() {
    SNode*temp=head;
    if (!temp) {
        printf("Danh sach khoa hoc trong\n");
        return;
    }
    printf("Danh sach khoa hoc dang hoc:\n");
    while (temp) {
        printf("ID: %d | Ten: %s | Tin chi: %d\n", temp->course.id, temp->course.title, temp->course.credit);
        temp=temp->next;
    }
}

void deleteCourse() {
    int id;
    printf("Nhap id khoa hoc muon xoa: ");
    scanf("%d", &id);
    SNode*temp=head;
    SNode*prev=NULL;
    while (temp!=NULL && temp->course.id != id) {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong tim thay khoa hoc\n");
        return;
    }
    if (prev==NULL) {
        head=temp->next; // xoa ptu dau
    }else {
        prev->next=temp->next;
    }
    free(temp);
    printf("Da xoa khoa hoc ID %d\n", id);
}

void updateCourse() {
    int id;
    printf("Nhap id khoa hoc can cap nhat: ");
    scanf("%d", &id);
    SNode*temp=head;
    while (temp!=NULL && temp->course.id != id) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong tim thay khoa hoc\n");
        return;
    }
    printf("Nhap ten moi: ");
    getchar();
    fgets(temp->course.title, sizeof(temp->course.title), stdin);
    temp->course.title[strcspn(temp->course.title,"\n")]='\0';
    printf("Nhap so tin chi moi: ");
    scanf("%d", &temp->course.credit);
    printf("Cap nhat thanh cong\n");
}

void markComleted() {
    int id;
    printf("Nhap id khoa hoc can danh dau hoan thanh: ");
    scanf("%d", &id);
    SNode*temp=head;
    SNode*prev=NULL;
    while (temp!=NULL && temp->course.id != id) {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Khong tim thay khoa hoc\n");
        return;
    }

    //tao Node ds doi
    DNode*newNode=(DNode*)malloc(sizeof(DNode));
    newNode->course=temp->course;
    newNode->prev=NULL;
    newNode->next=completedCourses;
    if (completedCourses!=NULL) {
        completedCourses->prev=newNode;
    }
    completedCourses=newNode;

    //xoa khoi ds don
    if (prev==NULL) {
        head=temp->next;
    }else {
        prev->next=temp->next;
    }
    free(temp);
    printf("Da danh dau hoan thanh va chuyen vao danh sach da hoan thanh!");
}

int main() {


    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1.Them khoa hoc\n");
        printf("2. Hien thi danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhat thong tin khoa hoc\n");
        printf("5. Danh dau khoa hoc da hoan thanh\n");
        printf("6. Sap xep khoa hoc theo so tin chi\n");
        printf("7. Tim kien khoa hoc theo ten\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();

        switch(choice) {
            case 1:
                addCourse();
                break;
            case 2:
                displayCourse();
                break;
            case 3:
                deleteCourse();
                break;
            case 4:
                updateCourse();
                break;
            case 5:
                markComleted();
                break;
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    }while (choice!=8);

    return 0;
}