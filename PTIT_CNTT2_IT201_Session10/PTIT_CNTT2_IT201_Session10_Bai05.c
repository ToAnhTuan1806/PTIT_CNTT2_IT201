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

void deleteByValue(Node**head, int x) {
    Node*current=*head;

    //xu ly cac node dau co gia tri can xoa
    while (current!=NULL && current->data==x) {
        Node*temp=current;
        current=current->next;
        free(temp);
    }
    *head=current;
    if (current==NULL) {
        return;
    }
    Node*prev=current;
    current=current->next;

    while (current!=NULL) {
        if (current->data==x) {
            Node*temp=current;
            prev->next=current->next;
            current=current->next;
            free(temp);
        }else {
            prev=current;
            current=current->next;
        }
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

    int x;
    printf("Nhap so nguyen can xoa: ");
    scanf("%d", &x);

    deleteByValue(&head,x);
    printList(head);
    return 0;
}