#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// duyet theo chieu sau: DFS

typedef struct Student {
    int id;
    char name[20];
};

typedef struct Node {
    int data;
    struct Node*left;
    struct Node*right;
}Node;

Node* createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("cap phat bo nho khong thanh cong\n");
        return NULL;
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//B2: Trien khai DFS
// cach 1: dung INORDER (LNR LEFT - NODE - RIGHT)
void inorder(Node* root) {
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}

// cach 2: dung PREOREDR (NLR NODE - LEFT - RIGHT)
void preorder(Node* root) {
    if (root==NULL) {
        return;
    }
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
}

// cach 3: dung POSTORDER (LRN LEFT - RIGHT - NODE)
void postorder(Node* root) {
    if (root==NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);
}

//B3: tao cay (TREE) trien khai trong main

int main() {
    Node*root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    //sau khi tao cay thi di duyet

    printf("Duyet cay theo INORDER: \n");
    inorder(root);

    printf("Duyet cay theo PREORDER: \n");
    preorder(root);

    printf("Duyet cay theo POSTORDER: \n");
    postorder(root);

    return 0;
}