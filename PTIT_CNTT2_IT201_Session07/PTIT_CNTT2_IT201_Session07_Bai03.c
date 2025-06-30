#include <stdio.h>

int insertionSort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int key=arr[i]; // ptu can chen
        int j=i-1;
        //doi cac ptu lon hon key sang phai
        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        // chen key vao dung vi tri
        arr[j+1]=key;
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n<=0||n>100) {
        printf("khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);
    printf("after: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}