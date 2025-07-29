#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    char email[50];
}Contact;

typedef struct TreeNode {
    Contact data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode*createNode(Contact c) {
    TreeNode*newNode=(TreeNode*)malloc(sizeof(TreeNode));
    newNode->data=c;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//so sanh ten khog phan biet chu hoa-thuong
int compareName(const char*a, const char*b) {
    return strcasecmp(a,b);
}

//them nguoi
TreeNode*insert(TreeNode*root, Contact c) {
    if (root==NULL) {
        return createNode(c);
    }
    int cmp=compareName(c.name, root->data.name);
    if (cmp<0) {
        root->left=insert(root->left, c);
    }else if (cmp>0) {
        root->right=insert(root->right, c);
    }else {
        printf("Ten %s da ton tai trong danh ba\n", c.name);
    }
    return root;
}

//duyet inorder
void inOrder(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    inOrder(root->left);
    printf("\nTen: %s\nSDT: %s\nEmail: %s\n", root->data.name, root->data.email, root->data.phone);
    inOrder(root->right);
}

//tim theo ten
TreeNode*search(TreeNode*root, const char*name) {
    if (root==NULL) {
        return NULL;
    }
    int cmp=compareName(root->data.name, name);
    if (cmp==0) {
        return root;
    }else if (cmp>0) {
        return search(root->left, name);
    }else {
        return search(root->right, name);
    }
}

// xoa theo ten:
TreeNode*deleteNode(TreeNode*root, const char*name) {
    if (root==NULL) {
        return NULL;
    }
    int cmp=compareName(name, root->data.name);
    if (cmp<0) {
        root->left=deleteNode(root->left, name);
    }else if(cmp>0) {
        root->right=deleteNode(root->right, name);
    }else {
        if (root->left==NULL) {
            TreeNode* temp=root->right;
            free(root);
            return temp;
        }else if (root->right==NULL) {
            TreeNode* temp=root->left;
            free(root);
            return temp;
        }
        //node co 2 con
        TreeNode*minRight=root->right;
        while (minRight->left!=NULL) {
            minRight=minRight->left;
        }
        root->data=minRight->data;
        root->right=deleteNode(root->right, minRight->data.name);
    }
    return root;
}

void freeNode(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

int main() {
    TreeNode*root=NULL;
    int choice;
    char name[50];

    do {
        printf("\n=== QUAN LY DANH BA ===\n");
        printf("1. Them nguoi vao danh ba\n");
        printf("2. Hien thi danh ba theo ABC\n");
        printf("3. Tim nguoi theo ten\n");
        printf("4. Xoa nguoi theo ten\n");
        printf("5. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                Contact c;
                printf("Nhap ho va ten: ");
                fgets(c.name, sizeof(c.name), stdin);
                c.name[strcspn(c.name, "\n")] = '\0';
                printf("Nhap so dien thoai: ");
                fgets(c.phone, sizeof(c.phone), stdin);
                c.phone[strcspn(c.phone, "\n")] = '\0';
                printf("Nhap email: ");
                fgets(c.email, sizeof(c.email), stdin);
                c.email[strcspn(c.email, "\n")] = '\0';

                root=insert(root, c);
                break;
            case 2:
                if (root==NULL) {
                    printf("Danh ba trong\n");
                }else {
                    inOrder(root);
                }
                break;
            case 3:
                printf("Nhap ten can tim: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                TreeNode*found=search(root, name);
                if (found) {
                    printf("\nTim thay: \nTen: %s\nSDT: %s\nEmail: %s\n",
                        found->data.name, found->data.email, found->data.phone);
                }else {
                    printf("khong tim thay %s trong danh ba\n", name);
                }
                break;
            case 4:
                printf("Nhap ten can xoa: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                TreeNode*result=search(root, name);
                if (result) {
                    root=deleteNode(root,name);
                    printf("da xoa %s khoi danh ba\n", name);
                }else {
                    printf("khong tim thay %s trong danh ba\n", name);
                }
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                freeNode(root);
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    }while (choice!=5);
    return 0;
}