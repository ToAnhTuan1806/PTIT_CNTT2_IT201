#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("Cap phat bo nho that bai");
        return NULL;
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int dfsSearch(Node*root, int value) {
    if (root==NULL) {
        return 0;
    }
    if (root->data==value) {
        return 1;
    }
    if (dfsSearch(root->left, value)) {
        return 1;
    }
    if (dfsSearch(root->right, value)) {
        return 1;
    }
    return 0;
}

int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    int value;
    printf("findValue: ");
    scanf("%d",&value);
    if (dfsSearch(root, value)) {
        printf("true\n");
    }else {
        printf("false\n");
    }

    return 0;
}