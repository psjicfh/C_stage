#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[1024] = "I like C program!";

    fp = fopen("1.txt", "r");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
    puts(str); //没“\n”也能换行
    printf("%s\n", str);
    fclose(fp);

    return 0;
}
