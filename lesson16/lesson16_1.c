#include <stdio.h>
#include <string.h>
//结构体不能包含自己但是能包含指向自己的指针
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
    STU *ptr = NULL;
    ptr = &stu1;

    stu1.num = 20;
    strcpy(stu1.name, "lilin");

    printf("num  name\n");
    printf("%d %s\n",ptr->num,stu1.name);

    return 0;
}
