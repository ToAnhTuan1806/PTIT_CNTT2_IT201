#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node*adjList[MAX];
int visited[MAX];

Node*createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node*nodeV=createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

   Node*nodeU=createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

void dfs(int u) {
    visited[u] = 1;
    printf("%d ",u);

    Node*temp = adjList[u];
    while(temp!=NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int v, e;
    printf("nhap so dinh (v) va so canh (e): ");
    scanf("%d%d", &v, &e);

    for (int i=0; i<v;i++) {
        adjList[i]=NULL;
        visited[i] = 0;
    }

    printf("nhap danh sach %d canh (u v): \n", e);
    for (int i=0; i<e;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }

    //nhap dinh dfs
    int start;
    printf("nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("cac dinh duoc duyet theo DFS tu %d: ", start);
    dfs(start);

    return 0;
}