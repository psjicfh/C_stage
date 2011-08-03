#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表 添加N个结点的链表即原链表为空

struct student
{
	int number;
	char name[20];
	struct student *next;
};

typedef	struct student STU;


int get_num(STU *p)
{
    int counter = 0;

    while(p != NULL)
    {
        counter++;
        p = p->next;
    }

    return counter;
}

void print_link(STU *p)
{
    if (p == NULL) //链表不存在
    {
        printf("empty\n");
        return;
    }

	while(p != NULL)
	{
		printf("%-5d  %s\n", p->number,p->name);
		p = p->next;
	}
}

STU *add_node(STU *p) //添加一个结点
{
    STU *head = p;
    STU *p_c = NULL;

    p_c = malloc(sizeof(STU));
    if (p_c == NULL) 
    {
        perror("malloc new");
        exit(0);
    }

    printf("please input number:\n");
    scanf("%d", &p_c->number);
    printf("input name:\n");
    scanf("%s",p_c->name);
    p_c->next = NULL;

    if (p == NULL) //被插入链表为空
    {
        return p_c; //打印要插入的结点（小链表）
    }

    if (p_c->number < p->number) 
    {
        p_c->next = p;
        head = p_c;
        return head;
    }

    while (p->next != NULL) 
    {
        if (p->next->number > p_c->number)//满足条件说明找到了插入点 
        {
            break;    
        }    
        p = p->next;
    }

    p_c->next = p->next; 
    //先赋值要插入结点的下一个结点要不然链表就断了
    //"p->next" 表示其指向的结构体的（首）地址 
    //在=右边表示存储空间的内容 在等号左边表示本身自己
    p->next = p_c;

    return head;
}

int main(int argc, const char *argv[])
{
    int counter = 0;
    int i;

	STU *head = NULL;

//	head = create_link(10);
	print_link(head);

    for (i = 0; i < 5; i++) 
    {
        head = add_node(head);
    }
    print_link(head);
    
    counter = get_num(head);
    printf("counter = %d\n",counter);

	return 0;
}//const 禁止修改内容

