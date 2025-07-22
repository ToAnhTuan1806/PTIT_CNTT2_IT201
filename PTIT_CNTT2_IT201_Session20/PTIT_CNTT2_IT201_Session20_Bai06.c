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

int findLevel(Node*root, int value, int level) {
    if (root==NULL) {
        return -1;
    }
    if (root->data==value) {
        return level;
    }
    int leftLevel=findLevel(root->left, value, level+1);
    if (leftLevel!=-1) {
        return leftLevel;
    }
    return findLevel(root->right, value, level+1);
}

int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    int value;
    printf("value: ");
    scanf("%d", &value);

    int level=findLevel(root, value, 0);
    if (level!=-1) {
        printf("Node level: %d\n", level);
    }else {
        printf("Node level not found\n");
    }
    return 0;
}
