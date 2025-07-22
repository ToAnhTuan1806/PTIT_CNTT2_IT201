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

void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    Node*Queue[100];
    int front=0, rear=0;
    Queue[rear++]=root;
    while(front < rear) {
        Node*current=Queue[front++];
        printf("%d\n",current->data);
        if (current->left!=NULL) {
            Queue[rear++]=current->left;
        }
        if (current->right!=NULL) {
            Queue[rear++]=current->right;
        }
    }
}

//xoa node cuoi cung
void deleteEnd(Node* root, Node*end) {
    if (root == end) {
        return;
    }
    if (root->left) {
        if (root->left==end) {
            free(root->left);
            root->left=NULL;
            return;
        }else {
            deleteEnd(root->left,end);
        }
    }
    if (root->right) {
        if (root->right==end) {
            free(root->right);
            root->right=NULL;
            return;
        }else {
            deleteEnd(root->right,end);
        }
    }
}

//xoa node theo gia tri
void deleteNode(Node* root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->left==NULL && root->right==NULL) {
        if (root->data==value) {
            free(root);
        }else {
            printf("khong tim thay gtri can xoa\n");
        }
        return;
    }
    Node*queue[100];
    int front=0, rear=0;
    queue[rear++]=root;
    Node*temp;
    Node*keyNode=NULL;

    while(front < rear) {
        temp=queue[front++];
        if (temp->data==value) {
            keyNode=temp;
        }
        if (temp->left!=NULL) {
            queue[rear++]=temp->left;
        }
        if (temp->right!=NULL) {
            queue[rear++]=temp->right;
        }
    }
    if (keyNode!=NULL) {
        int key=temp->data;
        deleteEnd(root, temp);
        keyNode->data=key;
    }
}

int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    root->left->right=createNode(6);

    printf("cay ban dau:\n");
    levelOrder(root);
    printf("\n");

    int deleteVal=3;
    printf("deleteValue: %d\n",deleteVal);
    deleteNode(root,deleteVal);

    printf("cay sau khi xoa:\n");
    levelOrder(root);
    printf("\n");

    return 0;
}