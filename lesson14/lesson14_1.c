#include <stdio.h>
#include <string.h>
//#define N 30

int main(int argc, const char *argv[])
{
    char *str = "abcdefg";
   // char *ptr = str;
    
    char *str1 = "cde";
   // char *ptr1 = str1;
    char *p = NULL;

    p = strstr(str,str1);
    if(p)
    {    
        printf("%s\n", p);
    }

    else 
    {
        printf("Not Found!");
    }

    return 0;
}
