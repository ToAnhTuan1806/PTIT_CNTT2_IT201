#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef  struct Student {
    int id;
    char name[100];
}Student;
typedef struct Node {
    int  vertex; // giá trị của đỉnh
    struct Node* next;
} Node;

Node* adjList[MAX]; // mảng chua các con trỏ của cac phan tu dinh de lien ket
int visited[MAX];// MẢNG ĐÁNH DẤU NHỮNG PHAN TỬ ĐÃ ĐI QUA
int n;// KHAI BÁO SỐ ĐIÊM CỦA ĐỒ THI
// HÀM TẠO NODE
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    // Tạo node
    Node* nodeV = createNode(v);
    // Tạo liên kết
    nodeV->next = adjList[u];
    adjList[u] = nodeV; // đưa về đầu danh sách liên kết

    // ĐỒ THỊ VÔ HƯỚNG CHO NÊN TẠO LIEN KẾT 2 CHIỀU
    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

void dfs(int u, int depth) {
    visited[u] = 1;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("Tham dinh %d\n", u);

    Node* temp = adjList[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {//0
            // kiểm tra xem Điểm vừa xét đã đi qua hay chưa
            for (int i = 0; i < depth; i++) printf("  ");
            printf("-> Goi de quy DFS(%d)\n", v);
            dfs(v, depth + 1);
        } else {
            for (int i = 0; i < depth; i++) printf("  ");
            printf("-> Dinh %d da tham:\n", v);
        }
        temp = temp->next;
    }
}

int main() {
    int edges;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;// gán giá ban đầu là 0 khi chưa duyệt
    }
    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("\n--- Bat dau DFS ---\n");
    // gọi hàm xem xuất phát từ điểm nào
    dfs(start, 0);
    return 0;
}