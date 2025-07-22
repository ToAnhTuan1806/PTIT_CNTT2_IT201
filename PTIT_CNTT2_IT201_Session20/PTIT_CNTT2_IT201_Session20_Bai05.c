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

int findMaxValue(Node* root) {
    if (root==NULL) {
        return 0;
    }
    int maxLeft=findMaxValue(root->left);
    int maxRight=findMaxValue(root->right);

    int max;
    if (maxLeft>maxRight) {
        max=maxLeft;
    }else {
        max=maxRight;
    }
    if (root->data>max) {
        return root->data;
    }else {
        return max;
    }
}

int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    printf("max value: %d\n", findMaxValue(root));
    return 0;
}