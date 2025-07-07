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

void printList(Node*head) {
    Node*current=head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current=current->next;
    }
    printf("NULL\n");
}

Node*insertAtHead(Node*head, int data) {
    Node*node=createNode(data);
    node->next=head;
    if (head!=NULL) {
        head->prev=node;
    }
    return node;
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

    printList(head);


    return 0;
}