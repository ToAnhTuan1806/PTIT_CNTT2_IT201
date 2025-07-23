#include<stdio.h>
#include<stdlib.h>

#define SIZE 3
typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("cap phat bo nho that bai");
        return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void addEdge(Node*graph[SIZE],int startNode,int endNode) {
    Node*newNode1=createNode(endNode);
    newNode1->next=graph[startNode];
    graph[startNode]=newNode1;

    Node*newNode2=createNode(startNode);
    newNode2->next=graph[endNode];
    graph[endNode]=newNode2;
}

void printGraph(Node*graph[SIZE]) {
    for (int i=0;i<SIZE;i++) {
        Node*temp=graph[i];
        if (temp==NULL) {
            printf("NULL");
        }else {
            while (temp!=NULL) {
                printf("%d->",temp->data);
                temp=temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Node*graph[SIZE]={NULL};

    int startNode=1;
    int endNode=2;
    printf("startNode=%d, endNode=%d\n",startNode, endNode);
    addEdge(graph,startNode,endNode);
    printGraph(graph);


    startNode=0;
    endNode=1;
    printf("startNode=%d, endNode=%d\n",startNode, endNode);
    addEdge(graph,startNode,endNode);
    printGraph(graph);

    return 0;
}