#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = -10;
    unsigned int b = 6;

    if ((a+b) < b) //在C语言中默认是 有符号数转无符号数
    {
        printf("hello\n");
    }
    else 
    {
        printf("world\n");
    }
    printf("c = %u\n",a+b); //%u打印无符号数

    return 0;
} //注：上函数中若a=-4，b=10则输出hello 原因是a+b溢出
