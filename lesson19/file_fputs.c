#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[1024] = "I like this C program!";

    fp = fopen("1.txt", "a+");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
    fputs(str, fp); //送一个字符串到一个流中
    fclose(fp);

    return 0;
}
