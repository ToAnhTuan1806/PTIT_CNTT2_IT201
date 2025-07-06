#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node*creatNode(int data) {
    Node*node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
    return node;
}

void printList(Node*head) {
    printf("NULL <-> ");
    Node*current=head;
    while(current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void swap(Node*head) {
    Node*current=head;
    while (current!=NULL && current->next!=NULL) {
        //hoan doi gtri data giua current va current->next
        int temp=current->data;
        current->data=current->next->data;
        current->next->data=temp;

        current=current->next->next;
    }
}

int main () {
    Node*first=creatNode(1);
    Node*second=creatNode(2);
    Node*third=creatNode(3);
    Node*fourth=creatNode(4);
    Node*fifth=creatNode(5);

    first->next=second;
    second->prev=first;

    second->next=third;
    third->prev=second;

    third->next=fourth;
    fourth->prev=third;

    fourth->next=fifth;
    fifth->prev=fourth;
    printList(first);
    swap(first);
    printList(first);

    return 0;
}