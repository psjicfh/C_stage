#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char str1[] = "how are you!";
	char str2[] = "how argc";

	int a = 0;

	a = strncmp(str1, str2, 7);
	printf("%s\n",strcat(str1,str2));
	printf("%d\n",a);

	return 0;
}
