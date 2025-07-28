#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

typedef struct {
    char action;
    char value;
}Operation;

typedef struct {
    Operation data[MAX];
    int top;
}Stack;

void initStack(Stack*s) {
    s->top=-1;
}
int isEmpty(Stack*s) {
    return s->top==-1;
}
int isFull(Stack*s) {
    return s->top==MAX-1;
}

void push(Stack*s, Operation op) {
    if (!isFull(s)) {
        s->data[++s->top]=op;
    }
}

Operation pop(Stack*s) {
    Operation op={'\0', '\0'};
    if (!isEmpty(s)) {
        op=s->data[s->top--];
    }
    return op;
}

int main() {
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);

    char text[MAX]="";

    int choice;
    char ch;
    do {
        printf("\n=== TEXT EDITOR ===\n");
        printf("1. INSERT x\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. HIEN THI\n");
        printf("5. THOAT\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("nhap ky tu muon them: ");
                scanf("%c", &ch);
                getchar();

                int len=strlen(text);
                text[len]=ch;
                text[len+1]='\0';

                Operation op;
                op.action='I';
                op.value=ch;
                push(&undoStack, op);
                initStack(&redoStack);
                break;
            case 2:
                if (!isEmpty(&undoStack)) {
                    Operation last = pop(&undoStack);
                    text[strlen(text) - 1] = '\0';
                    push(&redoStack, last);
                } else {
                    printf("khong co thao tac de hoan tac\n");
                }
                break;
            case 3:
                if (!isEmpty(&redoStack)) {
                    Operation last=pop(&redoStack);
                    int len=strlen(text);
                    text[len]=last.value;
                    text[len+1]='\0';
                    push(&undoStack, last);
                }else {
                    printf("khong co thao tac de phuc hoi\n");
                }
                break;
            case 4:
                printf("van ban hien tai: %s\n", text);
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai!\n");

        }
    }while (choice!=5);
    return 0;
}