#include <stdio.h>
#define N 30 

//void cp(char *ptr,char *ptr1);
char *my_copy(char *d,char *s);
int main(int argc, const char *argv[])
{
    char str[N] = "abcdefg";
    char str1[N];

//    cp(str,str1);
    my_copy(str1,str);
    printf("%s\n", str1);

    return 0;
}

/*void cp(char *ptr,char *ptr1)
{
    while (*ptr != '\0')
    {
        *ptr1 = *ptr;
        ptr++;
        ptr1++;
    }
    *ptr1 = '\0'; //打印字符串中的末尾
}*/

char *my_copy(char *d,char *s) //此函数相当于strcpy 还有strncpy    
{                              //可以用 “man strcpy”查看 
    char *m = d;
 /*   while ((*d = *s) != '\0') 
    {
        d++;
        s++;
    }*/
    
    while((*(d++) = *(s++)) != '\0');

    return m;
}
