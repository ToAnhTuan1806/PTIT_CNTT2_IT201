#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node*createNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void printList(Node*head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d -> ", current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void printNodes(Node*head) {
    int count=1;
    Node*current=head;
    while (current!=NULL) {
        printf("data: %d\n", current->data);
        current=current->next;
        count++;
    }
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
    printNodes(head);
    return 0;

}