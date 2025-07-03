#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node*createNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void printList(Node *head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void deleteLastNode(Node **head) {
    if (*head==NULL) {
        return;
    }
    if ((*head)->next==NULL) {
        free(*head);
        *head=NULL;
        return;
    }
    Node*current=*head;
    while (current->next->next!=NULL) {
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
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

    deleteLastNode(&head);
    printList(head);

    return 0;
}