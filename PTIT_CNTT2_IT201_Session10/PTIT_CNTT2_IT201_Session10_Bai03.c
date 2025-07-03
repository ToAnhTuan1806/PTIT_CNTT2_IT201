#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node*next;
} Node;

Node*createNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void printList(Node*head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
//them ptu vao cuoi danh sach
void addNodeToEnd(Node** head, int data) {
    Node*node=createNode(data);
    if (*head==NULL) {
        *head=node;
        return;
    }
    Node*current=*head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=node;
}

int main() {
    Node*head=createNode(5);
    Node*second=createNode(4);
    Node*third=createNode(3);
    Node*fourth=createNode(2);
    Node*fifth=createNode(1);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    printList(head);

    int value;
    printf("Nhap so nguyen can them: ");
    scanf("%d",&value);

    addNodeToEnd(&head,value);
    printList(head);

    return 0;
}