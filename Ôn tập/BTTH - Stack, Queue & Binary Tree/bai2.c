#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char fullName[50];
    char phoneNumber[15];
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

//so sanh sdt
int comparePhone(const char* a, const char* b) {
    return strcmp(a, b);
}

// them kahch hang
TreeNode* insert(TreeNode* root, Contact c) {
    if (root == NULL) return createNode(c);
    int cmp = comparePhone(c.phoneNumber, root->data.phoneNumber);
    if (cmp < 0)
        root->left = insert(root->left, c);
    else if (cmp > 0)
        root->right = insert(root->right, c);
    else
        printf("So dien thoai %s da ton tai!\n", c.phoneNumber);
    return root;
}

//duyet inorder
void inOrder(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    inOrder(root->left);
    printf("\nTen: %s\nSDT: %s\nEmail: %s\n", root->data.fullName, root->data.email, root->data.phoneNumber);
    inOrder(root->right);
}

//tim theo so dien thoai
TreeNode*search(TreeNode*root, const char*phone) {
    if (root==NULL) {
        return NULL;
    }
    int cmp=comparePhone(root->data.phoneNumber, phone);
    if (cmp==0) {
        return root;
    }else if (cmp>0) {
        return search(root->left, phone);
    }else {
        return search(root->right, phone);
    }
}

// xoa theo so dien thoai
TreeNode*deleteNode(TreeNode*root, const char*phone) {
    if (root==NULL) {
        return NULL;
    }
    int cmp=comparePhone(phone, root->data.phoneNumber);
    if (cmp<0) {
        root->left=deleteNode(root->left, phone);
    }else if(cmp>0) {
        root->right=deleteNode(root->right, phone);
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
        root->right=deleteNode(root->right, minRight->data.phoneNumber);
    }
    return root;
}

//dem tong so khach hang
int countNodes(TreeNode* root) {
    if (root==NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//tinh chieu cao cay
int treeHeight(TreeNode* root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight=treeHeight(root->left);
    int rightHeight=treeHeight(root->right);
    if (leftHeight>rightHeight) {
        return 1+leftHeight;
    }else {
        return 1+rightHeight;
    }
}

//liet ke email
void listGmailUsers(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    listGmailUsers(root->left);
    if (strstr(root->data.email, "@gmail.com")!=NULL) {
        printf("\nHo ten: %s\nSDT: %s\nEmail: %s\n", root->data.fullName, root->data.phoneNumber, root->data.email);
    }
    listGmailUsers(root->right);
}

//in khach hang co sdt = 09
void listPhone(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    listPhone(root->left);
    if (strncmp(root->data.phoneNumber, "09", 2)==0) {
        printf("\nHo ten: %s\nSDT: %s\nEmail: %s\n", root->data.fullName, root->data.phoneNumber, root->data.email);
    }
    listPhone(root->right);
}

int main() {
    TreeNode*root=NULL;
    int choice;
    char phone[15];

    do {
        printf("\n=== QUAN LY DANH BA SDT===\n");
        printf("1. Them khach hang\n");
        printf("2. Hien thi danh ba (tang dan theo SDT)\n");
        printf("3. Tim kiem theo SDT\n");
        printf("4. Xoa khach hang theo SDT\n");
        printf("5. Dem tong so khach hang\n");
        printf("6. Tinh chieu cao cua cay\n");
        printf("7. Liet ke khach hang co email @gmail.com\n");
        printf("8. Liet ke khach hang co SDT bat dau bang '09'\n");
        printf("9. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                Contact c;
                printf("Nhap ho va ten: ");
                fgets(c.fullName, sizeof(c.fullName), stdin);
                c.fullName[strcspn(c.fullName, "\n")] = '\0';
                printf("Nhap so dien thoai: ");
                fgets(c.phoneNumber, sizeof(c.phoneNumber), stdin);
                c.phoneNumber[strcspn(c.phoneNumber, "\n")] = '\0';
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
                printf("Nhap SDT can tim: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                TreeNode*found=search(root, phone);
                if (found) {
                    printf("\nTim thay: \nTen: %s\nSDT: %s\nEmail: %s\n",
                        found->data.fullName, found->data.email, found->data.phoneNumber);
                }else {
                    printf("khong tim thay SDT %s trong danh ba\n", phone);
                }
                break;
            case 4:
                printf("Nhap SDT can xoa: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                if (search(root, phone)) {
                    root = deleteNode(root, phone);
                    printf("Da xoa SDT %s khoi danh ba\n", phone);
                } else {
                    printf("Khong tim thay SDT %s\n", phone);
                }
                break;
            case 5:
                printf("Tong so khach hang: %d\n", countNodes(root));
                break;
            case 6:
                printf("Chieu cao cua cay: %d\n", treeHeight(root));
                break;
            case 7:
                printf("Khach hang co email @gmail.com:\n");
                listGmailUsers(root);
                break;
            case 8:
                printf("Khach hang co SDT bat dau bang '09':\n");
                listPhone(root);
                break;
            case 9:
                printf("Dang thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);
    return 0;
}