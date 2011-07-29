#include <stdio.h>
#define N 30
int main(int argc, const char *argv[])
{
    char str[N] = "abcdefg";
    char *ptr = str;
    char str1[N];
    char *ptr1 = str1;

    while (*ptr != '\0')
    {
        *ptr1 = *ptr;
        printf("%c",*ptr1); //……1 注:此句不能在下面，因为指针已经指向别处
        ptr++;
        ptr1++;
//        printf("%c",*ptr1);
    }
    printf("\n");
    printf("%s\n", str1);//没1句只有此句亦可

    return 0;
}
