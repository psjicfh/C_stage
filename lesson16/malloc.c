#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
    int num;
    char name[20];
    struct student *p;
};

typedef struct student STU;

int main(int argc, const char *argv[])
{
    STU *ptr = NULL;
    ptr = malloc(sizeof(STU));

    if (ptr == NULL)
    {
        perror("malloc");   // 判断空间是否开辟成功
        exit(0);
    }

    ptr -> num = 1;
    strcpy(ptr -> name ,"liu");

    printf("%5d          %s\n",ptr -> num, ptr -> name);
    return 0;
}
