#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL) {
        printf("cap phat bo nho that bai");
        return NULL;
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insertNode(Node*root,int value) {
    if(root==NULL) {
        return;
    }
    if (root->left==NULL) {
        root->left=createNode(value);
        return;
    }
    if (root->right==NULL) {
        root->right=createNode(value);
        return;
    }
    insertNode(root->left,value);
    insertNode(root->right,value);
}

void levelOrder(Node*root) {
    if(root==NULL) {
        return;
    }
    printf("%d\n",root->data);
    levelOrder(root->left);
    levelOrder(root->right);
}
int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    printf("Cay ban dau:\n");
    levelOrder(root);
    printf("\n");

    insertNode(root, 6);

    printf("Cay sau khi them:\n");
    levelOrder(root);

    return 0;
}