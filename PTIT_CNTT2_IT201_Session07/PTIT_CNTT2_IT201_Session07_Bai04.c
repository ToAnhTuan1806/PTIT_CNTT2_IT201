#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n=strlen(str);
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (str[j]>str[j+1]) {
                int temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}

int main() {
    char str[100];
    printf("Nhap vao chuoi ky tu bat ky: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';

    if (strspn(str, " \t")==strlen(str)) {
        printf("Chuoi khong hop le");
        return 0;
    }

    printf("str = %s\n", str);

    sortString(str);
    printf("str = %s", str);

    return 0;
}