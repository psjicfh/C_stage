#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	int number;
	char name[20];
	struct stu *next;
};

typedef	struct stu V_NODE;

char menu(void)
{
	puts("Please make a choice:");
	puts("1.add");
	puts("2.delete");
	puts("3.print");
	puts("4.save");
    puts("5.quit");

	return 0;
}


V_NODE *add_node(V_NODE *head)
{
	V_NODE *p = NULL;
	V_NODE *ptr = head;

	p = malloc(sizeof(V_NODE));
	if(NULL == p)
	{
		perror("malloc");
		exit(0);
	}

	puts("Please input number:");
	scanf("%d", &p->number);
	puts("Please input name:");
	scanf("%s", p->name);
	getchar();
	p->next = NULL;


	if(NULL == head)
	{
		return p;
	}

	if(p->number < head->number)
	{
		p->next = head;
		return p;
	}

	while((ptr->next != NULL) && (p->number > ptr->next->number))
	{
		ptr = ptr->next;
	}

	p->next = ptr->next;
	ptr->next = p;

	return head;
}

void show_link(V_NODE *p)
{
	if(NULL == p)
	{
		printf("empty\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d    %s\n", p->number,p->name);
		p = p->next;
	}

	return;
}

V_NODE *delete_node(V_NODE *head)
{
	int num = 0;
	V_NODE *p = head;
	V_NODE *temp = NULL;

	if(head == NULL)
	{
		printf("empty\n");
		return head;
	}

	puts("Please input number to delete:");
	scanf("%d", &num);
	getchar();

	if(num == head->number)
	{
		head = head->next;
		free(p);
		return head;
	}

	while((p->next != NULL)&&(p->next->number != num))
	{
		p = p->next;
	}
	if(p->next == NULL)
	{
		printf("No matched.\n");
	}
	else
	{
		temp = p->next;
		p->next = p->next->next;
		free(temp);
	}

	return head;
}

void save_data(V_NODE *p)
{
    FILE *fp = fopen("1.txt", "w+");
    if (NULL == fp) 
    {
        perror("open");
        exit(0);
    }
    while (p != NULL) 
    {
        fprintf(fp, "%d  %s\n",p->number, p->name);
        p = p->next;
    }
    fclose(fp);
}

V_NODE *read_data(void)
{
    V_NODE *head = NULL;
    V_NODE *p = NULL;
    int num;
    char iname[20];
    FILE *fp = fopen("1.txt","r+");
    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }

    if (fscanf(fp, %d%s, &num, iname) == EOF) 
    {
        return NULL;
    }

    head = p = malloc(sizeof(V_NODE));
    if(head == NULL)
    {
        perror("create");
        exit(0);
    }

    

    fscanf(fp,"%d%s", &num, iname);

}

int main(int argc, char *argv[])
{
	V_NODE *head = NULL;
	char choice = 0;
	char flag = 1;

//read from file
//    head = read_data();

	while(flag > 0)
	{
		menu();
		choice = getchar();
		getchar(); //清除回车
		switch(choice)
		{
			case '1' : head = add_node(head);break;
			case '2' : head = delete_node(head);break;
			case '3' : show_link(head);break;
			case '4' : save_data(head);break;
			case '5' : flag = 0;break; //这些语句中的 ‘5’ 是因为用的getchar
			default : break;
		}
	}
	return 0;
}

