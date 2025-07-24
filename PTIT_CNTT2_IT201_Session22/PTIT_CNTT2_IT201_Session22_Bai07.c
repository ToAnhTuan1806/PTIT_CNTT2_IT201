#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node*adjList[MAX];
int visited[MAX];

//hang doi cho bfs
int queue[MAX];
int front=0, rear=0;

void enqueue(int value) {
    queue[rear++]=value;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front==rear;
}

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=value;
    newNode->next=NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node*nodeV=createNode(v);
    nodeV->next=adjList[u];
    adjList[u]=nodeV;

    Node*nodeU=createNode(u);
    nodeU->next=adjList[v];
    adjList[v]=nodeU;
}

void bfs(int start) {
    enqueue(start);
    visited[start]=1;

    while(!isEmpty()) {
        int u=dequeue();
        printf("%d ", u);
        Node*temp=adjList[u];
        while(temp!=NULL) {
            int v=temp->vertex;
            if (!visited[v]) {
                enqueue(v);
                visited[v]=1;
            }
            temp=temp->next;
        }
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

    int start;
    printf("nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("cac dinh duoc duyet theo BFS tu %d: ", start);
    bfs(start);

    return 0;
}