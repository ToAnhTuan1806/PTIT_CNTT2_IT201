#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int value) {
    Node *newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("Cap phat bo nho that bai");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int value;
    printf("Nhap gia tri cho Node: ");
    scanf("%d", &value);
    Node *node = createNode(value);
    printf("   data: %d,\n", node->data);
    printf("   left->NULL,\n");
    printf("   right->NULL\n");

    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    return 0;
}