#include <stdio.h>
#define N 30
#define uchar unsigned char

int main(int argc, const char *argv[])
{
    uchar str[N] = "abcdefghij";
    uchar *ptr;
    ptr = str;
   // int i;
    while(*ptr != '\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");

    printf("%c",'\0');//此句本无可见打印为空

    while(ptr > str)
    {
        ptr--;
        printf("%c",*ptr);
    }
    
//    printf("%c",*ptr);

    printf("\n");
    
    return 0;
}
