# include <stdio.h>
# include <stdlib.h>

int main () {
    int n, m;
    printf("Nhap so luong phan tu n cua mang: ");
    scanf("%d", &n);

    if (n<=0 || n>=1000) {
        printf("khong hop le thu lai\n");
        return 1;
    }

    int *arr= (int *)malloc(n*sizeof(int));
    for (int i=0; i<n ;i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap so luong phan tu m cua mang: ");
    scanf("%d", &m);

    int total=n+m;

    int *newArr= (int*)malloc(total*sizeof(int));
    for (int i=0; i<n ;i++) {
        newArr[i]=arr[i];
    }

    // them m ptu vao cuoi mang moi
    for (int i=n; i<total; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &newArr[i]);
    }
    free(arr);

    //in mang moi
    for (int i=0; i<total; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");
    free(newArr);
    return 0;

}