//b1: doi cap dau tien 1 va 2
//first=1
//second=2
//second->first
//first tro den node tiep theo 3

//b2:
//first[3]
//second[4]
//doi cho second first
//first->null

//CODE
//current: chinh la code first trg moi cap
//second=current-> next(la node thu 2)
//nextPair=second->next: node dau cua cap tiep theo

//second->next=current
//current->next=nextPair

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

//ham tao node moi va them vao danh sach
Node*insertAtTail(Node* head, int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL) {
        return newNode;
    }
    Node*temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

//ham hien thi
void printList(Node* head) {
    Node*current=head;
    while(current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

//ham doi vi tri 2 phan tu lien ke
Node*swap(Node* head) {
    Node*newHead=head->next;
    Node*prev=NULL;
    Node*current=head;
    while(current!=NULL && current->next!=NULL) {
        Node*nextPair=current->next->next;
        Node*second=current->next;
        second->next=current;
        current->next=nextPair;

        if (prev!=NULL) {
            prev->next=second;
        }

        prev=current;
        current=nextPair;
    }
    return newHead;
}
int main() {
    Node*head=NULL;
    head=insertAtTail(head,1);
    head=insertAtTail(head,2);
    head=insertAtTail(head,3);
    head=insertAtTail(head,4);
    head=insertAtTail(head,5);
    printf("before: ");
    printList(head);
    head=swap(head);
    printf("after: ");
    printList(head);
    return 0;
}