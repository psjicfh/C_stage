#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *fp = NULL;
    char str[1024] = "I like C\n program!";
    char r_str[1024] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//    char *p = r_str;
    int n = 0;
    fp = fopen("3.txt", "r+");

    if (fp == NULL) //判断是否打开成功
    {
        perror("open");
        exit(0);
    }
                                        
    fwrite(str, 1, strlen(str), fp);

//    rewind(fp);//复位文件指针 若无此句则下面读的时候为空
    //因为上面语句执行完成以后fp已经指向了末位
    fseek(fp, 0, SEEK_SET); //fp指向文件开始
    fread(r_str, 1, 1023, fp);
    printf("%s\n", r_str);

    rewind(fp); //因为指真已经指向最后
    n = fread(r_str, 1, 1023, fp);
    r_str[n] = '\0'; //当printf函数遇到'\0'认为字符串结束前面的a全已被覆盖

    printf("%s\n", r_str);

    fclose(fp);

    return 0;
}

