
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

// xoa phan tu tai vi tri bat ky
void deletePosition(Node** head, int position) {
    if (*head==NULL|| position<0) {
        return;
    }
    Node*temp=*head;
    if (position==0) {
        *head=temp->next;
        free(temp);
        return;
    }

    Node*prev=NULL;
    int index=0;
    while (temp!=NULL && index<position) {
        prev=temp;
        temp=temp->next;
        index++;
    }
    if (temp==NULL) {
        printf("vi tri vuot qua do dai danh sach");
        return;
    }
    prev->next=temp->next;
    free(temp);
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

    int pos;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &pos);

    deletePosition(&head, pos);
    printList(head);


    return 0;
}