//B1: Duyet qua cac ky tu trong chuoi Hau To
//B2: Voi tung ky tu:
    //-Gap toan hang (Chu||So): dua vao Stack duoi dang chuoi
    //-Gap toan tu (+,-,*,/): Pop 2 phan tu tu Stack ra => Gop lai (X+Y) ==> Push lai vao Stack
//B3: Thuc hien het thao tac duyet xong thi Stack chi con lai 1 phan tu
//==> Bieu thuc cuoi cung chinh la bieu thuc trung to


#include <ctype.h>
#include <stdio.h>
#include <string.h>
//khai bao ctruc ngan xep
#define MAX 100
#define LEN 100

typedef struct {
    char data[MAX][LEN];
    //MAX: so luong cac bieu thuc co the chua trong stack
    //LEN: do dai toi da cua moi bieu thuc dang chuoi

    int top;
} Stack;
// hao tac vs ngan xep
// khoi tao ngan xep
// sau khi khoi tao di them ptu vao ngan xep, trc khi them ktra xem ngan xep da day hay chua
// khi xoa ptu trong ngan xep thi phai ktra ngan xep co rong hay khong

// HAm khoi tao ngan xep
void init_stack(Stack*s) {
    s->top=-1;// ban dau rong
}

// Ham them ptu vao Stack
void push(Stack*s, char* str) {
    //trc khi them ktra stack co day hay k
    if (s->top==MAX-1) {
        printf("stack overflow\n");
        return;
    }
    //sap chep chuoi vao trong stack
    strcpy(s->data[++s->top], str);
    //tang gia tri top len 1
}

// Ham lay phan tu ra
char * pop(Stack* s) {
    // ktra neu stack k co ptu thi k xoa duoc
    if (s->top==-1) {
        printf("stack is empty\n");
        return "";
    }
    //lay ptu ra sau do giam top 1 don vi
    return s->data[s->top--];
}

// Ham chuyen cac ky tu HAu to sang Trung to
char* postfixInfix(char* postfix) {
    Stack s;
    init_stack(&s);
    //duyet tung ky tu torng mang pstfix
    for (int i=0; postfix[i]!='\0'; i++) {
        char c=postfix[i];
        //ktra tung ky tu
        //neu la so dua vao stack
        if (isdigit(c)) {
            char temp[]={c, '\0'};
            push(&s, temp);
        }else if (c=='+'|| c=='-'||c== '*'|| c=='/') {
            //lay toan hang 1 va 2 roi gop lai
            char*element2=pop(&s);
            char*element1=pop(&s);
            //tao mang de luu cac ptu khi gop
            char temp[LEN*2];
            snprintf(temp, LEN*2, "%s%c%s", element2, element1);
            //sau khi gop lai thi push stack
            push(&s, temp);
        }
        //neu la toan tu pop toan hang 1 va 2 gop lai
    }
    return pop(&s);
}

int main() {
    char str[MAX];
    printf("Nhap bieu thuc hau to: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    char *result = postfixInfix(str);
    printf("%s\n", result);
    return 0;
}
