#include <stdio.h>
#include <string.h>

struct student
{   
    int num;
    char name[20];
};

typedef struct student STU;

int main(void)
{
/*  struct student
    {
        int num;
        char name[20];
    }stu1 = {10010,"lilin"};*/
    STU stu1;

    stu1.num = 20;
    strcpy(stu1.name, "lilin");

    printf("num  name\n");
    printf("%d %s\n",stu1.num,stu1.name);

    return 0;
}
