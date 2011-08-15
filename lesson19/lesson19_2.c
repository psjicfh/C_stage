#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[1024] = "I like C\n program!";
    char r_str[1024] = {0};

    fp = fopen("2.txt", "w+");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
    int i = 0;
    while (str[i] != '\0') 
    {
        putc(str[i], fp);
        i++;
    }
    fclose(fp);

    return 0;
}

