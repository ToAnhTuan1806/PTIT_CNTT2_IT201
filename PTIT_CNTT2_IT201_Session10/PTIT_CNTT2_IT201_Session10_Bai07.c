#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void printList(Node* head) {
    Node* current=head;
    while(current!=NULL) {
        printf("%d -> ", current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void sortList(Node* head) {
    Node*current;
    Node*lastSort=NULL;
    int temp;

    if (head==NULL || head->next==NULL) {
        return;
    }
    int swap;
    do {
        swap=0;
        current=head;
        while (current->next!=lastSort) {
            if (current->data>current->next->data) {
                temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
                swap=1;
            }
            current=current->next;
        }
        lastSort=current;
    }while (swap);
}
int main() {
    Node*head=createNode(5);
    Node*second=createNode(7);
    Node*third=createNode(3);

    head->next=second;
    second->next=third;

    printList(head);
    sortList(head);

    printList(head);
    return 0;
}