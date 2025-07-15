#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

typedef struct Node {
    char command[MAX_LEN];
    struct Node *next;
}Node;

typedef struct Stack {
    Node*top;
}Stack;

void initStack(Stack *s) {
    s->top=NULL;
}
int isEmpty(Stack *s) {
    return s->top==NULL;
}

//day lenh vao stack
void push(Stack*s, const char* cmd) {
    Node*newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL) {
        printf("Cap phat bo nhat that bai\n");
        return;
    }
    strcpy(newNode->command,cmd);
    newNode->next=s->top;
    s->top=newNode;
}

//xoa lenh khoi stack, tra ve node
Node* pop(Stack *s) {
    if(isEmpty(s)) {
        return NULL;
    }
    Node*temp=s->top;
    s->top=s->top->next;
    return temp;
}

//xoa sach stack
void clearStack(Stack *s) {
    while (!isEmpty(s)) {
        Node*temp=pop(s);
        free(temp);
    }
}

//hien thi ls stack tu moi den cu nhat
void displayHistory(Stack *s) {
    if(isEmpty(s)) {
        printf("Lich su trong\n");
        return;
    }
    printf("=== Lich su lenh ===\n");
    Node*temp=s->top;
    while (temp!=NULL) {
        printf("%s\n",temp->command);
        temp=temp->next;
    }
}


int main() {
    Stack historyStack;
    initStack(&historyStack);
    Stack redoStack;
    initStack(&redoStack);

    int choice;
    char input[MAX_LEN];

    do {
        printf("\n======= TERMINAL HISTORY =======\n");
        printf("1. INSERT lenh moi\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. HIEN THI lich su\n");
        printf("5. THOAT\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Nhap lenh moi: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                push(&historyStack, input);
                clearStack(&redoStack);
                printf("Da them lenh moi\n");
                break;
            case 2:
                Node*undone=pop(&historyStack);
                if (undone) {
                    push(&redoStack, undone->command);
                    printf("Da undo lenh: %s\n", undone->command);
                    free(undone);
                }else {
                    printf("Khong co lenh nao de undo\n");
                }
                break;
            case 3:
                Node*redone=pop(&redoStack);
                if (redone) {
                    push(&historyStack, redone->command);
                    printf("Da redo lenh: %s\n", redone->command);
                    free(redone);
                }else {
                    printf("Khong co lenh nao de redo\n");
                }
                break;
            case 4:
                displayHistory(&historyStack);
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai\n");
        }

    }while (choice!=5);



    return 0;
}