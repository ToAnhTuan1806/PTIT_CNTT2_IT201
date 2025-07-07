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

void findMiddle(Node*head) {
    int count=0;
    Node*current=head;
    while (current != NULL) {
        count++;
        current=current->next;
    }
    int middle;
    if (count%2==0) {
        middle=count/2+1;
    }else {
        middle=count/2+1;
    }
    current=head;
    for (int i=1; i<middle; i++) {
        current=current->next;
    }
    printf("Node %d: %d\n", middle, current->data);
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
    findMiddle(head);


    return 0;
}