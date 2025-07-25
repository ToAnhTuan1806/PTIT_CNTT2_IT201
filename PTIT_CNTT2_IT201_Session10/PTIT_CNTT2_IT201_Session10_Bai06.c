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
    while(current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

void findMiddleNode(Node*head) {
    int count=0;
    Node*temp=head;
    while(temp!=NULL) {
        count++;
        temp=temp->next;
    }
    if (count==0) {
        printf("Danh sach rong");
        return;
    }
    int middle=count/2;
    Node*current=head;
    int index=1;
    for (int i=0; i<middle; i++) {
        current=current->next;
        index++;
    }
    printf("Node %d: %d\n", index, current->data);
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
    findMiddleNode(head);

    return 0;
}