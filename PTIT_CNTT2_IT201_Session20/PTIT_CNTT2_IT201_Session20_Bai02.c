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
        printf("cap phat bo nho that bai\n");
        return NULL;
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// N-L-R
void preorder(Node*root) {
    if (root==NULL) {
        return;
    }
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
}
// L-N-R
void inorder(Node*root) {
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}
// L-R-N
void postorder(Node*root) {
    if (root==NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);
}


typedef struct QNode {
    Node* treeNode;
    struct QNode* next;
}QNode;

typedef struct {
    QNode*front;
    QNode*rear;
}Queue;

void initQueue(Queue* q) {
    q->front=NULL;
    q->rear=NULL;
}

int isEmpty(Queue* q) {
    return q->front==NULL;
}

void enqueue(Queue*q, Node* node) {
    QNode*newNode=(QNode*)malloc(sizeof(QNode));
    newNode->treeNode=node;
    newNode->next=NULL;
    if (q->rear==NULL) {
        q->front=newNode;
        q->rear=newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QNode*temp=q->front;
    Node*treeNode=temp->treeNode;
    q->front=q->front->next;
    if (q->front==NULL) {
        q->rear=NULL;
    }
    free(temp);
    return treeNode;
}

// Level-order
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enqueue(&q,root);
    while (!isEmpty(&q)) {
        Node*current=dequeue(&q);
        printf("%d\n",current->data);
        if (current->left!=NULL) {
            enqueue(&q,current->left);
        }
        if (current->right!=NULL) {
            enqueue(&q,current->right);
        }
    }
}
int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);

    printf("Duyet cay theo PREORDER:\n");
    preorder(root);
    printf("\n");

    printf("Duyet cay theo INORDER:\n");
    inorder(root);
    printf("\n");

    printf("Duyet cay theo POSTORDER:\n");
    postorder(root);
    printf("\n");

    printf("Duyet cay theo LEVER-ORDER:\n");
    levelOrder(root);

    return 0;
}