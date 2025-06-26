#include <stdio.h>

int fibonacci(int arr[], int n, int index) {
    if (index>=n) {
        return;
    }
    if (index==0) {
        arr[index]=0;
    } else if (index==1) {
        arr[index]=1;
    }else {
        arr[index]=arr[index-1]+arr[index-2];
    }
    fibonacci(arr, n, index+1);
}

int main() {
    int n;
    printf("Nhap vao so nguyen duong bat ky: ");
    scanf("%d", &n);
    int arr[n];
    fibonacci(arr, n, 0);
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}