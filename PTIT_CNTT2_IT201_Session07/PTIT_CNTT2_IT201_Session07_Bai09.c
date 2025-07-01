//b1: nhap so luong ptu, nhap gia tri tung ptu trong mang
//b2: tao 2 mang chua cac so chan va so le
//b3: + doi voi mang so chan sap xep tang dan - doi voi mang so le sap xep giam dan
//b4: gop 2 mang chan va le
//b5: hien thi ket qua

#include <stdio.h>

int sort(int arr[], int n) {
    int count_even=0, count_odd=0;
    for (int i=0; i<n; i++) {
        if (count_even%2==0) {
            count_even++;
        }else {
            count_odd++;
        }
    }
    int even[count_even];
    int odd[count_odd];
    int evenCount=0, oddCount=0;// bien dem de them vao mang so chan hoac le
    for (int i=0; i<n;i++) {
        if (arr[i]%2==0) {
            even[evenCount]=arr[i];
            evenCount++;
        }else {
            odd[oddCount]=arr[i];
            oddCount++;
        }
    }
    //tien hanh sap xep mang so chan theo thu tu tang dan
    for (int i=0; i<evenCount-1; i++) {
        for (int j=0; j<evenCount-i-1; j++) {
            if (even[j]>even[j+1]) {
                int temp=even[j];
                even[j]=even[j+1];
                even[j+1]=temp;
            }
        }
    }

    //tien hanh sap xep mang so le theo thu tu gian dan
    for (int i=0; i<oddCount-1; i++) {
        for (int j=0; j<oddCount-i-1; j++) {
            if (odd[j]<odd[j+1]) {
                int temp=odd[j];
                odd[j]=odd[j+1];
                odd[j+1]=temp;
            }
        }
    }

    //gop 2 mang da duoc sap xep
    int k=0;
    for (int i=0; i<oddCount;i++) {
        arr[k]=even[i];
        k++;
    }
    for (int i=0; i<oddCount;i++) {
        arr[k]=odd[i];
        k++;
    }

}

int main() {
    int n;
    printf("Nhap so luong ptu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}