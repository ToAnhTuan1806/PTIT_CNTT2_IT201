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

//dem so luong phan tu
int countNodes(Node* head) {
    int count=0;
    Node* current=head;
    while (current!=NULL) {
        count++;
        current=current->next;
    }
    return count;
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

    int count=countNodes(head);
    printf("Danh sach lien ket co %d phan tu", count);

    return 0;
}