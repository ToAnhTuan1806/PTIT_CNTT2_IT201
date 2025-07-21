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

typedef struct QueueN {
    Node* treeNode;
    struct QueueN* next;
}QueueN;

typedef struct {
    QueueN* front;
    QueueN* rear;
}Queue;

void initQueue(Queue* q) {
    q->front=NULL;
    q->rear=NULL;
}

int isEmpty(Queue* q) {
    return q->front==NULL;
}

void enqueue(Queue* q, Node*treeNode) {
    QueueN* newNode=(QueueN*)malloc(sizeof(QueueN));
    newNode->treeNode=treeNode;
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
    QueueN* temp=q->front;
    Node*treeNode=temp->treeNode;
    q->front=q->front->next;
    if (q->front==NULL) {
        q->rear=NULL;
    }
    free(temp);
    return treeNode;
}

void levelOrder(Node* root, int value) {
    if (root==NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enqueue(&q,root);
    while (!isEmpty(&q)) {
        Node*current=dequeue(&q);
        if (current->left==NULL) {
            current->left=createNode(value);
            return;
        }else {
            enqueue(&q,current->left);
        }
        if (current->right==NULL) {
            current->right=createNode(value);
            return;
        }else {
            enqueue(&q,current->right);
        }
    }
}
void preorderTraversal(Node *root) {
    if (root==NULL) {
        return;
    }
    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    printf("cay truoc khi them:\n");
    preorderTraversal(root);
    printf("\n");


    levelOrder(root,6);
    printf("cay sau khi them:\n");
    preorderTraversal(root);
    return 0;
}