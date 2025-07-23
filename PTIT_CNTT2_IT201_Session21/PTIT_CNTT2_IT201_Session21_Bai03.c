#include<stdio.h>

#define SIZE 3

void initGraph(int graph[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            graph[i][j]=0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    if (startNode>=0 && startNode<SIZE && endNode>=0 && endNode<SIZE) {
        graph[startNode][endNode]=1;
    }
}

void printGraph(int graph[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE];
    initGraph(graph);

    addEdge(graph,1,2);

    printGraph(graph);
    return 0;
}