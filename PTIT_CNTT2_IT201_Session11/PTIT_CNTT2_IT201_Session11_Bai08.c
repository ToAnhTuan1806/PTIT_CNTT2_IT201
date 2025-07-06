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

Node*deleteAt(Node*head, int index) {
    if (head==NULL) {
        printf("danh sach trong");
        return head;
    }
    Node*current=head;
    if (index==1) {
        head=head->next;
        if (head!=NULL) {
            head->prev=NULL;
        }
        free(current);
    }else {
        int i;
        for (int i=1; i<index && current!=NULL; i++) {
            current=current->next;
        }
        if (current==NULL) {
            printf("vi tri khong hop le");
            return head;
        }
        if (current->prev!=NULL) {
            current->prev->next=current->next;
        }
        if (current->next!=NULL) {
            current->next->prev=current->prev;
        }
        free(current);
    }
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

    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);
    first=deleteAt(first,pos);
    printList(first);

    return 0;
}