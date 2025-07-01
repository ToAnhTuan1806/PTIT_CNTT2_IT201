//b1: tao mang gom cac ptu, tao gia tri x
//b2: sap xep cac pty theo khoang cach toi X theo dieu kien
    //+ neu khoang cach lon hon doi cho
    //+ neu kkhoang cach bang nhau di so sanh gia tri
//b3: hien thi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//tao ham sap xep cac ptu theo khoang cach
int sortByDistance(int arr[], int x ,int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            int temp1=abs(arr[j]-x);
            int temp2=abs(arr[j+1]-x);
            if (temp1>temp2 || temp1==temp2 && arr[j]>arr[j+1]) {
                //thoa man dieu kien di doi cho
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int arr[]= {10, 5, 3, 9, 2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int x=7;
    sortByDistance(arr, x, size);
    for (int i=0; i<x; i++) {
        printf("%d ", arr[i]);
    }

}