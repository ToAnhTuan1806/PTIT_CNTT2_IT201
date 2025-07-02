
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

//them ptu vao dau danh sach
void insertNode(Node** head, int data) {
    Node*node=createNode(data);
    node->next=*head;
    *head=node;
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
    int value;
    printf("Nhap so nguyen duong can them vao dau danh sach: ");
    scanf("%d", &value);
    insertNode(&head, value);
    printList(head);

    return 0;
}