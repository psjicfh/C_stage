#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表(重点)

static int crunode = 0; //结点个数 全局变量定义在段空间
                 //局部变量定义在栈空间
                 //static只能在本文件中用 即限制了其的可见性
//extern int count; 声明外部变量
//注：在main函数开始定义的变量不是真正的全局变量，只有一个文件时可以认为是全局变量

struct student
{
	int number;
	char name[20];
	struct student *next;
};

typedef	struct student STU;

STU *create_link(int n)
{
//    static i = 0; 此局部变量内存不释放，只能初始化一次放在静态存储区
	int i = 0;
	STU *head1 = NULL;
	STU *p = NULL;

	head1 = p = malloc(sizeof(STU));
	if(p == NULL)
	{
		perror("create");
		exit(0);
	}
	p->number = 1;
	strcpy(p->name, "student");
	p->next = NULL;
	
	for(i=1; i<n; i++)
	{
		p->next = malloc(sizeof(STU));
		if(p->next == NULL)
		{
			perror("create");
			exit(0);
		}
		p->next->number = i+1;
		strcpy(p->next->name, "student");
		p->next->next = NULL;
		p = p->next; // 使p指向下一个结点
	}
	return head1;
}

void print_link(STU *p)
{
	while(p != NULL)
	{
		printf("%-5d  %s\n", p->number,p->name);
		p = p->next;

        crunode++;//结点个数
	}
}
int main(int argc, const char *argv[])
{
	STU *head = NULL;

	head = create_link(10);
	print_link(head);
    printf("crunode = %d\n",crunode);
	return 0;
}//const 禁止修改内容
