#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
//    char str[1024] = "I like C program!";
    char r_str[1024] = {0};

    fp = fopen("1.txt", "r");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
    gets(r_str); //用此函数时有不可避免的警告 所以尽量是自己调试的时候用
    printf("%s\n", r_str);
    fclose(fp);

    return 0;
}

