#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//链表 删除一个结点
struct student
{
	int number;
	char name[20];
	struct student *next;
};

typedef	struct student STU;

STU *create_link(int n)
{
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
		p = p->next;

	}

	return head;
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

STU *delete_link(STU *p)
{
	STU *head = p;
	STU *temp = NULL;
	int num = 0;

    if (p == NULL) 
    {
        printf("empty\n");//链表不存在
        return NULL;
    }

	printf("Please input the number to delete: ");
	scanf("%d", &num);
//    printf("\n");

    if (p->number == num) 
    {
        head = p->next;
        free(p); //释放内存
        return head;
    }

	while(p->next != NULL)
	{
		if(p->next->number == num)
		{
			break;
		}
		p = p->next;
	}

    if (p->next == NULL) 
    {
        printf("No find num:%d\n",num);    
        return head;
    }

    temp = p->next;
	p->next = p->next->next; 
    //同理在=右边表示存储空间的内容 在等号左边表示本身自己
	free(temp);  //若此三行放在上一个if语句上面会有断错误

	return head;
	
}

int main(void)
{
    int counter = 0;

	STU *head = NULL;

	head = create_link(10);
	print_link(head);
//	head = add_node(head);
//	print_link(head);

	head = delete_link(head);
	print_link(head);

    counter = get_num(head);
    printf("counter = %d\n",counter);

	return 0;
}
