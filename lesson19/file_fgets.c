#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char r_str[1024] = {0};

    fp = fopen("1.txt", "r");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
    fgets(r_str, 1023, fp);//最多读1023个字符
    printf("%s\n", r_str);
    fclose(fp);

    return 0;
}

