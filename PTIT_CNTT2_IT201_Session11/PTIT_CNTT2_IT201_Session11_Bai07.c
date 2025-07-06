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

Node*insertAt(Node*head, int data, int index) {
    Node* node = creatNode(data);
    if (index == 1) {
        node->next = head;
        if (head != NULL) {
            head->prev = node;
        }
        head = node;
        return head;
    }

    Node* current = head;
    int i;
    for (i = 1; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Vị trí không hợp lệ\n");
        free(node);
        return head;
    }
    node->next = current->next;
    node->prev = current;
    if (current->next != NULL) {
        current->next->prev = node;
    }
    current->next = node;
    return head;
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

    int val, pos;
    printf("Nhap gia tri can chen: ");
    scanf("%d",&val);
    printf("Nhap vi tri muon them: ");
    scanf("%d",&pos);

    first=insertAt(first,val,pos);
    printList(first);

    return 0;
}