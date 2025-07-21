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

int bfsSearch(Node*root, int value) {
   if (root==NULL) {
       return 0;
   }

    Node*queue[100];
    int front=0, rear=0;
    queue[rear++]=root;

    while (front<rear) {
        Node*current=queue[front++];
        if (current->data==value) {
            return 1;
        }
        if (current->left!=NULL) {
            queue[rear++]=current->left;
        }
        if (current->right!=NULL) {
            queue[rear++]=current->right;
        }
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
    if (bfsSearch(root, value)) {
        printf("true\n");
    }else {
        printf("false\n");
    }

    return 0;
}