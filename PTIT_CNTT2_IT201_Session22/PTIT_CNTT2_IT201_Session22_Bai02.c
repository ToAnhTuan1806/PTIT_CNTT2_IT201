#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

Node*adjList[MAX];
Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=value;
    newNode->next=NULL;
    return newNode;
}
// them vao dau danh sach
void addEdge(int u, int v) {
    Node*nodeV=createNode(v);
    nodeV->next=adjList[u];
    adjList[u]=nodeV;

    Node*nodeU=createNode(u);
    nodeU->next=adjList[v];
    adjList[v]=nodeU;
}

void printMatrix(int n) {
    for (int i=0; i<n; i++) {
        Node*temp=adjList[i];
        printf("%d: ",i);
        while(temp!=NULL) {
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, u, v;
    printf("nhap so dinh: ");
    scanf("%d", &n);

    for (int i=0; i<=n; i++) {
        printf("nhap canh (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printMatrix(n);
    return 0;
}