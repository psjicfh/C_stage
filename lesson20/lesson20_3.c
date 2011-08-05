#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[1024] = "I like C program!";
    char r_str[1024] = {0};

    fp = fopen("2.txt", "r+");

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

    fseek(fp, -10, SEEK_END); //fp指向距文件结尾-10个字节

    i = 0;
    while ((r_str[i] = getc(fp)) != EOF) 
    {
        i++;
    }
    r_str[i] = '\0';
    printf("%s\n", r_str);

    fclose(fp);

    return 0;
}

