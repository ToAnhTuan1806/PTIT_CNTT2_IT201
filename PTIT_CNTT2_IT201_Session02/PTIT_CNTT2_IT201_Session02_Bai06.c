# include <stdio.h>

int main () {
    int n, pos, value;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n<=0|| n>100) {
        printf("phan tu khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    printf("Nhap vi tri muon them phan tu: ");
    scanf("%d", &pos);
    if (pos<0 || pos>=n) {
        printf("vi tri khong hop le\n");
        return 1;
    }

    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    //dich cac ptu sau vi tri sang phai
    for (int i=n; i>pos; i--) {
        arr[i] = arr[i-1];
    }
    //them ptu moi vao vi tri
    arr[pos] = value;
    n++;

    for (int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}