#include <stdio.h>
#include <string.h>
//结构体不能包含自己但是能包含指向自己的指针

//利用一个结构体中的指针（元素），给另一个结构体赋值
//注：两个结构体中的结构体的元素是一样儿的
//下面的结构体中，student：结构体名， stu1 stu2 结构体变量 
//                大括弧中的是结构体元素  
struct student
{   
    int num;
    char name[20];
    struct student *p;
};

typedef struct student STU;

int main(void)
{
    STU stu1;
    STU stu2;//定义了stu1和stu2两个结构体变量，其里面的元素一样儿

    STU *ptr = NULL;
    ptr = &stu1;//让指针指向结构体stu1
    ptr->p = &stu2;//指针操作结构体中的元素

    ptr->p->num = 5;
    strcpy(ptr->p->name, "lilin");

    printf("num  name\n");
    printf(" %d   %s\n",ptr->p->num, ptr->p->name);

    return 0;
}

