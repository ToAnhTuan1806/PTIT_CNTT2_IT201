#include <stdio.h>

int check(char str[]) {
    int i=0;
    while (str[i]!='\0') {
        if (str[i]<'0' || str[i]>'9') {
            return 0;// ky tu khog hop le

        }
        i++;
    }
    return 1;// ky tu hop le
}

// ham de quy chuyen doi
int change(char str[], int index, int val) {
    if (str[index]=='\0') {
        return val;
    }
    return change(str, index+1, val*10+str[index]-'0');
}

int main() {
    char str[100];
    printf("Nhap chuoi ky tu bat ky: ");
    scanf("%s", str);
    if (!check(str)) {
        printf("khong hop le\n");
        return 0;
    }
    int result=change(str, 0, 0);
    printf("%d", result);

    return 0;
}