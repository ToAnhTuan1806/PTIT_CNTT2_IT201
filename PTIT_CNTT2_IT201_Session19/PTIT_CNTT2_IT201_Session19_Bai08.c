#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("Cap phat bo nho khong thanh cong\n");
        return NULL;
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int treeHeight(Node* root) {
    if (root==NULL) {
        return -1; // node hien tai la NULL thif chieu cao =-1
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    if (leftHeight > rightHeight) {
        return 1+leftHeight;
    }else {
        return 1+rightHeight;
    }
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int height=treeHeight(root);
    printf("%d\n",height);
}