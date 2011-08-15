#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[1024] = "I like this program!";

    printf("%s\n",str);
    fp = fopen("1.txt", "w"); 
    //在此之前未创建“1.txt” "w"亦可创建，而是r就不行

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
    
//    fprintf(fp,"%s\n", str);
    fclose(fp);

    return 0;
}
