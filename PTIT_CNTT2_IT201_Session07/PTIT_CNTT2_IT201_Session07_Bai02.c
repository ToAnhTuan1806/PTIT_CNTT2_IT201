#include <stdio.h>

int selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex = i; // gia su ptu min
        for (int j=i+1; j<n; j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j; // cap nhat vi tri ptu min
            }
        }
        // hoan doi vi tri
        if (minIndex!=i) {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>100) {
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

    selectionSort(arr, n);
    printf("before: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }



    return 0;
}