#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Folder {
    char name[100];
    struct Folder *parent;
    struct Folder *firstChild;
    struct Folder *nextSibling;
}Folder;



