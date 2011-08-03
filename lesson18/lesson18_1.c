#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表  删除一个结点

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
	STU *head = NULL;
	STU *p = NULL;

	head = p = malloc(sizeof(STU));
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
	return head;
}

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
	while(p != NULL)
	{
		printf("%-5d  %s\n", p->number,p->name);
		p = p->next;
	}
}

STU *delete_node(STU *p) //添加一个结点
{
    STU *head = p;
    STU *temp = NULL;
    int number = 0;

    printf("please input number:\n");
    scanf("%d", &number);
    //printf("input name:\n");
    //scanf("%s",p_c->name);
   // p_c->next = NULL;

    while (number != p->number && p->next != NULL) 
    {
        temp = p; p = p->next;
    }

    if(number == p->number)
    {
        if (p == head) 
        {
            head = p->next;    
        }

        else 
        {
            temp->next = p->next;
        }

    }

    else 
    {
        printf("not find:%d\n",number);
    }
    
    
    return head;
}

int main(int argc, const char *argv[])
{
    int counter = 0;

	STU *head = NULL;

	head = create_link(10);
	print_link(head);

    head = delete_node(head);
    print_link(head);
    
    counter = get_num(head);
    printf("counter = %d\n",counter);

	return 0;
}//const 禁止修改内容

