#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[55];
    int age;
};
int main () {
    struct Student students[5];
    for (int i=0; i<5; i++) {
        printf("Nhap thong tin sinh vien so %d:\n", i+1);
        printf("id: ");
        scanf("%d", &students[i].id);
        printf("name: ");
        scanf("%s", &students[i].name);
        printf("age: ");
        scanf("%d", &students[i].age);
    }
    int searchID;
    printf("Nhap id sinh vien can tim: ");
    scanf("%d", &searchID);

    int index=-1;
    for (int i=0; i<5; i++) {
        if (students[i].id==searchID) {
            index=i;
            break;
        }
    }
    if (index!=-1) {
        printf("id: %d, name: %s, age: %d\n", students[index].id, students[index].name, students[index].age);
    } else {
        printf("Sinh vien khong ton tai");
    }



    return 0;
}
