#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
//C->A->B
Node* createNode(int data) {
    //b1: Cap phat bo nho dong cho 1 Node
    Node*node=(Node*)malloc(sizeof(Node));
    //b2: Cung cap data cho node
    node->data=data;
    //b3: Trỏ node moi tao ra den NULL(next, prev)
    node->next=NULL;
    node->prev=NULL;
    return node;
}
// Get All - Lay ra toan bo phan tu co trong Dslk doi
void printList(Node* head) {
    printf("NULL <-> ");
    Node*current=head;
    while (current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

int getLength(Node*head) {
    Node*current=head;
    int length=0;
    while (current!=NULL) {
        current=current->next;
        length++;
    }
    return length;
}

// Get One
Node* getOne(Node*head, int index) {
    //b1: kiem tra xem index co hop le hay khog
    if (index<0 || index>getLength(head)) {
        printf("index out of range\n");
        return NULL;
    }
    //b2: Ap dung ky thuat di chuyen (current) de duyet den vi tri index
    Node*current=head;
    for (int i=0; i<index; i++) {
        current=current->next;
    }
    return current;
}

 Node* inserHead(Node*head, int data) {
    //b1: tao ra node moi
    Node*node=createNode(data);
    //b2: Lien ket node moi -> head
    node->next=head;
    //b3: Lien ket node head -> node moi
    if (head!=NULL) {
        head->prev=node;
    }
    //b4: Tra ve node moi lam head cua dslk da duoc them 1 phan tu vao dau tien
    return node;
}

Node* inserEnd(Node*head, int data) {
    //b1: Tao ra node moi
    Node*node=createNode(data);
    //b2: Kiem tra neu dslk rong -> tra ve node moi
    if (head==NULL) {
        return node;
    }
    //b3: Lay ra thong tin cua node tail(cuoi cung) bang viec duyet tu node head
    Node*current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    //b4: tao ra su lien ket giua node cuoi (tail) <-> node moi
    current->next=node;
    node->prev=current;
    return head;
}

Node* insertAt(Node*head, int data, int index) {
    //b1: kiem tra index co hop le hay khong
    if (index<0 || index>getLength(head)) {
        printf("index out of range\n");
        return head;
    }
    //b2: neu index=0 -> insert dau
    if (index==0) {
        return inserHead(head, data);
    }
    //b3: neu index = length -> insert cuoi
    if (index==getLength(head)) {
        return inserEnd(head, data);
    }
    //b4: duyet den vi tri cua node can chen
    Node*current=head;
    for (int i=0; i<index; i++) {
        current=current->next;
    }
    //b5: khi da co thong tin cua vi tri node can chen(current)
    //tao moi 1 node
    Node*node=createNode(data);
    Node*prev=current->prev;
    //b6: Tao ra su lien ket giua
    //node <-> current
    node->next=current;
    current->prev=node;
    //prev <-> node
    prev->next=node;
    node->prev=prev;
    return head;

}

Node* removeHead(Node*head) {
    //b1: ktra xem dslk doi co rong khog
    if (head==NULL) {
        return NULL;
    }
    //b2: Luu node muon xoa (node dau) vao bien tam thoi
    Node*temp=head;
    //b3: Cho node nam canh node head tro thanh head moi
    head=head->next; //co the NULL
    //b4: ktra neu node head co ton tai (dslk co nhieu hon 1 phan tu)
    if (head!=NULL) {
        head->prev=NULL;
    }
    //b5: giai phong bo nho cua node cu
    free(temp);
    return head;
}

Node* removeEnd(Node*head) {
    //b1: ktra neu dslk doi rong
    if (head==NULL) {
        return NULL;
    }
    //b2: Ktra xem dslk co phai co 1 ptu hay khong
    if (head->next==NULL) {
        free(head);
        return NULL;
    }
    //b3: Lay thong tin ve node cuoi cung duyet tu head ->
    Node*current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    //b4: cap nhat lai node ke cuoi tro next toi NULL
    current->prev->next=NULL;
    //b5: giai phong node cuoi cung di
    free(current);
    return head;

}

Node* removeAt(Node*head, int index) {
    //b1: ktra xem vi tri index co hop le hay khong
    if (index<0 || index>getLength(head)-1) {
        printf("index out of range\n");
        return head;
    }
    //b2: ktra cac truong hop dac biet
    if (index==0) {
        return removeHead(head);
    }
    if (index==getLength(head)-1) {
        return removeEnd(head);
    }
    //b3: duyet den vi tri index -> de xoa node do
    Node*current=head;
    for (int i=0; i<index; i++) {
        current=current->next;
    }
    //b4: lay ra thong tin cua node dang truoc current
    Node*prev=current->prev;
    //b5: lay ra thong tin cua node dang sau current
    Node*next=current->next;
    //b6: luu tru thong tin cua node can xoa vao 1 bien temp
    Node* temp=current;
    // b7: Cap nhat lai lj cua node prev<->next
    prev->next=next;
    next->prev=prev;
    //b8: xoa, giai phong bo nho cua node temp
    free(temp);
    return head;
}

int main() {
    Node*head=createNode(1);
    Node*node2=createNode(2);
    Node*node3=createNode(3);

    //head<->node2<->node3
    head->next=node2;
    node2->prev=head;
    node2->next=node3;
    node3->prev=node2;

    printList(head);
    int length=getLength(head);
    printf("Length: %d\n", length);
    Node*findNode=getOne(head, 1);
    printf("Node1: %d\n", findNode->data);


    // Thêm node vào đầu cua dslk
    head=inserHead(head, 24);
    head=inserHead(head, 18);
    // printList(head);

    // Thêm node vào vị trí cuối cùng
    head=inserEnd(head, 6);
    // printList(head);

    // Thêm node vao vị trí bất kỳ
    head=insertAt(head, 26, 3);
    // printList(head);

    // Xoá node
    head=removeHead(head);
    head=removeHead(head);
    head=removeEnd(head);
    head=removeEnd(head);
    head=removeAt(head, 2);
    printList(head);
    return 0;
}