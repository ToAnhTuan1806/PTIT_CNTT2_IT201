#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node*createNode(int data) {
    Node*current=(Node*)malloc(sizeof(Node));
    current->data=data;
    current->next=NULL;
    current->prev=NULL;
    return current;
}

Node*insertAtHead(Node*head, int data) {
    Node*node=createNode(data);
    node->next=head;
    if (head!=NULL) {
        head->prev=node;
    }
    return node;
}

Node*insertAtTail(Node*head, int data) {
    Node*node=createNode(data);
    if (head==NULL) {
        return node;
    }
    Node*current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=node;
    node->prev=current;
    return head;
}

void printList(Node*head) {
    Node*current=head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main() {
    Node*head=NULL;
    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        printf("Nhap phan tu %d: ",i);
        scanf("%d", &value);
        head=insertAtHead(head, value);
    }

    printf("Nhap gia tri muon them vao cuoi danh sach: ");
    scanf("%d", &value);
    head=insertAtTail(head, value);
    printList(head);


    return 0;
}