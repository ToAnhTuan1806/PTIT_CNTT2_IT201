#include <stdio.h>

#define SIZE 4

void initGraph(int graph[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
    if (firstNode>=0 && firstNode<SIZE && secondNode>=0 && secondNode<SIZE) {
        graph[firstNode][secondNode] = 1;
        graph[secondNode][firstNode] = 1;
    }
}

void printGraph(int graph[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[SIZE][SIZE];
    initGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);
    return 0;
}