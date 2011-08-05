#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
//    char str[1024] = "I like C program!";
    char r_str[1024] = {0};

    fp = fopen("2.txt", "w+");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
    fgets(r_str, 1023, stdin); 
    fputs(r_str,stdout);
//    fclose(fp);

    return 0;
}
