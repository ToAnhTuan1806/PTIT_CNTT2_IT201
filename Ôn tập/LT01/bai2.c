#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct  Node*left;
    struct Node*right;
}Node;

Node*createNode(int value) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node*insert(Node*root,int value) {
    if (root==NULL) {
        printf("da them gia tri %d vao cay\n ",value);
        return createNode(value);
    }
    if (value<root->data) {
        root->left=insert(root->left,value);
    }else if (value>root->data) {
        root->right=insert(root->right,value);
    }else {
        printf("gia tri da ton tai\n");
    }
    return root;
}

Node*deleteNode(Node*root,int value) {
    if (root==NULL) {
        printf("khong tim thay gia tri %d de xoa\n", value);
        return NULL;
    }
    if (value<root->data) {
        root->left=deleteNode(root->left,value);
    }else if (value>root->data) {
        root->right=deleteNode(root->right,value);
    }else {
        if (root->left==NULL) {
            Node*temp=root->right;
            printf("da xoa gia tri %d\n", root->data);
            free(root);
            return temp;
        }else if (root->right==NULL) {
            Node*temp=root->left;
            printf("da xoa gia tri %d\n", root->data);
            free(root);
            return temp;
        }else {
            //neu Node co 2 con: tim node nho nhat ben phai
            Node* minNode = root->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    return root;
}

void inorder(Node*root) {
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//dem so la
int countLeaves(Node*root) {
    if (root==NULL) {
        return 0;
    }
    if (root->left==NULL && root->right==NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

//tinh chieu cao cua cay
int height(Node*root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int maxHeight;
    if (leftHeight > rightHeight) {
        maxHeight = leftHeight;
    }else {
        maxHeight = rightHeight;
    }
    return 1+maxHeight;
}

int main() {
    Node*root = NULL;
    int choice, x;
    do {
        printf("\n=== BINARY SEARCH TREE MANAGER ===\n");
        printf("1. THEM GIA TRI x\n");
        printf("2. XOA GIA TRI X\n");
        printf("3. DUYET GIA TRI (INORDER)\n");
        printf("4. DEM LA\n");
        printf("5. CHIEU CAO\n");
        printf("6. THOAT\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("nhap gia tri can them: ");
                scanf("%d", &x);
                root=insert(root, x);
                break;
            case 2:
                printf("nhap gia tri can xoa: ");
                scanf("%d", &x);
                root=deleteNode(root, x);
                break;
            case 3:
                if (root==NULL) {
                    printf("cay rong\n");
                }else {
                    printf("duyet Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                printf("so luong nut la: %d\n", countLeaves(root));
                break;
            case 5:
                printf("chieu cao cua cay: %d\n", height(root));
                break;
            case 6:
                printf("thoat chuong trinh\n");
                break;
            default:
                printf("lua chon khong hop le. thu lai\n");
        }

    }while (choice != 6);
    return 0;
}