#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

typedef struct Node {
    char text[MAX_LEN];
    struct Node*next;
}Node;

typedef struct Stack {
    Node* top;
}Stack;

void initStack(Stack*s) {
    s->top=NULL;
}
int isEmpty(Stack*s) {
    return s->top==NULL;
}
void push(Stack*s, const char* text) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->text,text);
    newNode->next=s->top;
    s->top=newNode;
}
//lay gtri dau
char*peek(Stack*s) {
    if (!isEmpty(s)) {
        return s->top->text;
    }
    return NULL;
}
//pop khoi stack
char*pop(Stack*s) {
    if (isEmpty(s)) {
        return NULL;
    }
    Node*temp=s->top;
    char*text=(char*)malloc((MAX_LEN*sizeof(char)));
    strcpy(text,temp->text);
    s->top=temp->next;
    free(temp);
    return text;
}
//xoa toan bo stack
void clearStack(Stack*s) {
    while (!isEmpty(s)) {
        Node*temp=s->top;
        s->top=s->top->next;
        free(temp);
    }
}
//hien thi nd stack
void printStack(Stack*s) {
    if (isEmpty(s)) {
        printf("Clipboard trong\n");
        return;
    }
    Node*temp=s->top;
    printf("Noi dung clipboard (moi nhat->cu nhat):\n");
    while (temp != NULL) {
        printf(" %s\n",temp->text);
        temp=temp->next;
    }
}

int main() {
    Stack clipboardStack, redoStack;
    initStack(&clipboardStack);
    initStack(&redoStack);

    int choice;
    char buffer[MAX_LEN];

    do {
        printf("\n=== CLIPBOARD MANAGER ===\n");
        printf("1. COPY\n");
        printf("2. PASTE\n");
        printf("3. UNDO\n");
        printf("4. REDO\n");
        printf("5. HIEN THI\n");
        printf("6. THOAT\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1://COPY
                printf("nhap noi dung can sao chep: ");
                fgets(buffer, MAX_LEN, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                push(&clipboardStack, buffer);
                clearStack(&redoStack);
                printf("da sao chep: %s\n", buffer);
                break;
            case 2://PASTE
                if (!isEmpty(&clipboardStack)) {
                    printf("noi dung paste: %s\n", peek(&clipboardStack));
                }else {
                    printf("Clipboard trong\n");
                }
                break;
            case 3://UNDO
                if (!isEmpty(&clipboardStack)) {
                    char* undone=pop(&clipboardStack);
                    push(&redoStack, undone);
                    printf("hoan tac: %s\n", undone);
                    free(undone);
                }else {
                    printf("khong co gi de hoan tac\n");
                }
                break;
            case 4://REDO
                if (!isEmpty(&clipboardStack)) {
                    char* redone=peek(&redoStack);
                    push(&clipboardStack, redone);
                    printf("khoi phuc: %s\n", redone);
                    free(redone);
                }else {
                    printf("khong co gi de khoi phuc\n");
                }
                break;
            case 5:
                printStack(&clipboardStack);
                break;
            case 6:
                printf("thoat chuong trinh thanh cong\n");
                clearStack(&clipboardStack);
                clearStack(&redoStack);
                return 0;
            default:
                printf("lua chon khong hop le\n");
        }
    }while (choice!=6);
    return 0;
}