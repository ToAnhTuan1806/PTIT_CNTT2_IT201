#include <stdio.h>
// cach 1: sắp xếp mảng rôi kiểm tra liền kề
int soft(int arr[], int n) {
    int tempArr[n];
    for (int i=0; i<n; i++) {
        tempArr[i]=arr[i];
    }
    // sap xep noi bot
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (tempArr[j]>tempArr[j+1]) {
                int temp=tempArr[j];
                tempArr[j]=tempArr[j+1];
                tempArr[j+1]=temp;
            }
        }
    }
    // kiem tra phan tu lien nhau co trung lap khong
    for (int i=0; i<n-1; i++) {
        if (tempArr[i]==tempArr[i+1]) {
            return 1;
        }
    }
    return 0;
}

// cach 2: dùng mảng đếm
int arrCount(int arr[], int n) {
    int count[1001];
    for (int i=0; i<=1000; i++) {
        count[i]=0;
    }
    for (int i=0; i<n; i++) {
        if (count[arr[i]]>0) {
            return 1; // neu co ptu trung lap
        }
        count[arr[i]]++;
    }
    return 0; // neu khong co ptu trung lap
}


int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Cac phan tu cua mang:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int duplicate1= soft(arr, n);
    if (duplicate1) {
        printf("cach 1: Co %d phan tu trung lap\n", duplicate1);
    } else {
        printf("cach 1: Khong co phan tu trung lap\n");
    }
    int duplicate2= arrCount(arr, n);
    if (duplicate2) {
        printf("cach 2: Co phan tu trung lap\n");
    } else {
        printf("cach 2: Khong co phan tu trung lap\n");
    }
}

// cách 1: độ phức tạp là O(n^2) vì cần duyệt nhiều lần tất cả ptu cần so sánh, đổi chỗ
// cách 2: độ phức tạp là O(n) vì chỉ cần duyệt qua mảng một lần