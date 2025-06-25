#include <stdio.h>

int binanySearch(int arr[], int low, int high, int search) {
    if (low <= high) {
        int mid = (low+high)/2;
        if (search==arr[mid]) {
            return mid;
        } else if (search<arr[mid]) {
            return binanySearch(arr, low, mid-1, search);
        }else {
            return binanySearch(arr, mid+1, high, search);
        }
    } else {
        return -1;
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

}