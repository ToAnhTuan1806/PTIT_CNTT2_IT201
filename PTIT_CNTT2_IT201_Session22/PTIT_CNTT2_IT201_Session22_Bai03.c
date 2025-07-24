#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node*adjList[MAX];//ds ke
int matrix[MAX][MAX];//ma tran ke

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=value;
    newNode->next=NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node*newNode=createNode(v);
    newNode->next=adjList[u];
    adjList[u]=newNode;
}

void printMatrix(int n) {
    for(int i=0;i<n;i++) {
        printf("%d: ", i);
        Node*temp=adjList[i];
        while(temp!=NULL) {
            printf("%d -> ", temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d",&n);
    int matrix[MAX][MAX];

    printf("nhap ma tran ke:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=n-1;j>=0;j--) {
            if(matrix[i][j]==1) {
                addEdge(i,j);
            }
        }
    }
    printMatrix(n);
    return 0;
}