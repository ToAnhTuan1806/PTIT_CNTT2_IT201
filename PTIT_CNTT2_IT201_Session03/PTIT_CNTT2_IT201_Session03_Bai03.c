#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int sum=0;
    int a;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>1000) {
        printf("khong hop le thu lai\n");
        return 1;
    }
    int *arr=malloc(n*sizeof(int));
        for (int i=0; i<n;i++) {
            printf("phan tu thu %d: ", i+1);
            scanf("%d", &arr[i]);
        }

        for (int i=0; i<n; i++) {
            if (arr[i]%2==0) {
                sum+=arr[i];
                a++;
            }
        }
    int average= sum/a;
    printf("average = %d", average);
    free(arr);
    return 0;

}
