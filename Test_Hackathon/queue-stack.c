#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
    char phoneNumber[20];
    char time[30];
}Call;

typedef struct QNode {
    Call call;
    struct QNode *next;
}QNode;

typedef struct {
    QNode *front;
    QNode *rear;
}Queue;

QNode*createQNode(Call call) {
    QNode*newNode=(QNode*)malloc(sizeof(QNode));
    newNode->call=call;
    newNode->next=NULL;
    return newNode;
}

typedef struct SNode {
    Call call;
    struct SNode *next;
}SNode;

typedef struct {
    SNode *top;
}Stack;

SNode* createSNode(Call call) {
    SNode*newNode=(SNode*)malloc(sizeof(SNode));
    newNode->call=call;
    newNode->next=NULL;
    return newNode;
}

//lay time hien tai
void getCurrentTime(char*buffer) {
    time_t t= time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(buffer,"%02d-%02d-%04d %02d:%02d:%02d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
}


//thao tac voi Queue
void initQueue(Queue* q) {
    q->front=NULL;
    q->rear=NULL;
}

//them 1 cuoc goi
void enQueue(Queue* q, Call call) {
    QNode*newNode=createQNode(call);
    if (q->rear==NULL) {
        q->front=newNode;
        q->rear=newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}
//hien thi toan bo ls da goi
void displayQueue(Queue* q) {
    if (q->front==NULL) {
        printf("Lich su cuoc goi rong\n");
        return;
    }
    printf("LICH SU CUOC GOI\n");
    QNode*current=q->front;
    while (current!=NULL) {
        printf("So: %s - Thoi gian: %s\n", current->call.phoneNumber, current->call.time);
        current=current->next;
    }
}

//thao tac voi Stack
void initStack(Stack* s) {
    s->top=NULL;
}
int isEmpty(Stack* s) {
    return s->top==NULL;
}

//push 1 cuoc goi len stack
void push(Stack* s, Call call) {
    SNode* newNode = createSNode(call);
    newNode->next=s->top;
    s->top=newNode;
}
//xoa cuoc goi tren cung khoi stack
int pop(Stack* s, Call* call) {
    if (isEmpty(s)) {
        return 0;
    }
    SNode*current=s->top;
    *call=current->call;
    s->top=s->top->next;
    free(current);
    return 1;
}
//dem so ptu trong stack
int countStack(Stack* s) {
    int count=0;
    SNode*current=s->top;
    while (current!=NULL) {
        count++;
        current=current->next;
    }
    return count;
}
//xoa toan bo
void clearStack(Stack* s) {
    Call tmp;
    while (pop(s,&tmp)) {}
}
//hien thi cuoc goi hien tai tren top cua stack
void displayTop(Stack* s) {
    if (!isEmpty(s)) {
        printf("Dang o so: %s\n", s->top->call.phoneNumber);
    }
}


int main() {
 Queue history;
    Stack back;
    Stack forward;

    initQueue(&history);
    initStack(&back);
    initStack(&forward);

    int choice;
    char phoneNumber[20];

    while (1) {
        printf("\n=== QUAN LY LICH SU CUOC GOI ===\n");
        printf("1. CALL\n");
        printf("2. BACK\n");
        printf("3. REDIAL\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar();

        Call currentCall;
        char timeBuffer[30];

        switch (choice) {
            case 1:
                printf("Nhap so dien thoai muon goi: ");
                fgets(phoneNumber, sizeof(phoneNumber), stdin);
                phoneNumber[strcspn(phoneNumber, "\n")] = '\0';

                strcpy(currentCall.phoneNumber, phoneNumber);
                getCurrentTime(timeBuffer);
                strcpy(currentCall.time, timeBuffer);

                push(&back, currentCall);
                enQueue(&history, currentCall);
                clearStack(&forward);

                printf("Dang goi so: %s - Thoi gian: %s\n", currentCall.phoneNumber, currentCall.time);
                break;

            case 2:
                if (countStack(&back) >= 2) {
                    pop(&back, &currentCall);
                    push(&forward, currentCall);
                    printf("Da quay lai so truoc.\n");
                    displayTop(&back);
                } else {
                    printf("Khong co cuoc goi nao truoc de quay lai.\n");
                }
                break;

            case 3:
                if (pop(&forward, &currentCall)) {
                    push(&back, currentCall);
                    printf("Dang goi lai so: %s\n", currentCall.phoneNumber);
                } else {
                    printf("Khong co so nao de goi lai.\n");
                }
                break;

            case 4:
                displayQueue(&history);
                break;

            case 5:
                printf("Dang thoat chuong trinh...\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Thu lai!\n");
        }
    }

    return 0;
}