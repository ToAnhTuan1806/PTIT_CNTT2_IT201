#include <stdio.h>
void main(void) {
    int arr[]= {1, 2, 3, 4, 5, 3, 3, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxCount=0;
    int maxItem;
    for (int i=0; i<size; i++) {
        int count=0;
        for (int j=0; j<size; j++) {
           if (arr[i]==arr[j]) {
               count++;
           }
        }
        // kthuc for di ktra count va maxCount
        if (count>maxCount) {
            maxCount=count;
            maxItem=arr[i];
        }
    }
    printf("ptu lon nhat: %d\n ",maxItem);
}

// độ phức tạp là O(n^2) vì có hai vòng lập lồng nhau, mỗi ptu thực hin so sánh với ptu khac

