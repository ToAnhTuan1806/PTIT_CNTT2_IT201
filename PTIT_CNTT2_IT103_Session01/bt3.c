#include <stdio.h>
#include <stdlib.h>

int * mallocArray(int n) {
        int *arr = (int*)mallocArray(n* sizeof(int));
        for (int i=0; i<n; i++) {
            arr[i]=1;
        }
        return 0;
    }
int main() {
        int n=10;
        int *array=mallocArray(n);
        free(array);
        return 0;
    }
// Độ phức tạp O(n)
