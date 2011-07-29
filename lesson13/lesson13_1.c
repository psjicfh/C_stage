#include <stdio.h>
#define uchar unsigned char
#define N 30 

int main(int argc, const char *argv[])
{
    int i;
    uchar c[N];
    uchar *ptr = c;
    for (i = 0; i < N-1; i++,ptr++) 
    {
        *ptr = 'a' + i;
        printf("%2c",c[i]);  //……1 
    }
    *ptr = '\0';
    printf("\n");

    printf("%s\n",c); //……2   2句和1句有一个即可
    return 0;
}  //注：字符串的结尾是'\0' 字符数组则可有可无
