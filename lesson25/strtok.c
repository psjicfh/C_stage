#include <stdio.h>
#include <string.h>
//就是函数返回第一个分隔符分隔的子串后，将第一参数设置为NULL，函数将返回剩下的子串。
int main(int argc, const char *argv[])
{
	char str[] = "gcc mlain.c -l o malin";
	char *p;
	int i;
	p = strtok(str, " ");
	while (*p != '\0') {
		printf("%c",*p);
		p++;
	}
	printf("\n");

	for (i = 0; i < 4; i++) 
	{
		p = strtok(NULL, "l"); 

		while (*p != '\0') {
			printf("%c",*p);
			p++;
		}
		printf("\n");
	}
	return 0;
}

//方法二
/*
int main(int argc, const char *argv[])
{
	char str[] = "gcc mlain.c -l o malin";
	char *p;
	int i;
	p = strtok(str, " ");
	printf("%s\n",p);

	for (i = 0; i < 4; i++) 
	{
		p = strtok(NULL, "l"); 
		printf("%s\n",p);
	}
	return 0;
}
*/

//方法三
 
/*int main(int argc, const char *argv[])
{
	int i;
	char str[] = "gcc -Wall -o main  main.c";
	char *p[6];
	p[0] = strtok(str, " ");
	for (i = 1; i < 5; i++) 
	{
		p[i] = strtok(NULL, "  ");
	}
	
	for (i = 0; i < 5; i++) {
		printf("%s",p[i]);
		printf("\n");
	}

	return 0;
}*/
