
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node*createNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//them ptu vao vi tri bat ky
void insertPosition(Node**head, int value, int position) {
    Node*node=createNode(value);

    if (position==0 || *head==NULL) {
        node->next=*head;
        *head=node;
        return;
    }
    Node*current=*head;
    int index=0;

    //duyet den vi tri trc vi tri can chen
    while (current!=NULL && index<position-1) {
        current=current->next;
        index++;
    }

    //neu hop le
    if (current!=NULL) {
        node->next=current->next;
        current->next=node;
    }else {
        printf("khong chen duoc");
    }
}
int main() {
    Node*head=createNode(1);
    Node*second=createNode(2);
    Node*third=createNode(3);
    Node*fourth=createNode(4);
    Node*fifth=createNode(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    printList(head);

    int val, pos;
    printf("Nhap gia tri: ");
    scanf("%d", &val);
    printf("Nhap vi tri: ");
    scanf("%d", &pos);

    insertPosition(&head, val, pos);
    printList(head);

    return 0;
}