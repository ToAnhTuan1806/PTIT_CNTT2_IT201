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

int countLeaves(Node*root) {
    if (root==NULL) {
        return 0;
    }
    if (root->left ==NULL && root->right ==NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);

}

int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    printf("So la cua cay: %d\n", countLeaves(root));
    return 0;
}