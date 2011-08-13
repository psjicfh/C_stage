//十进制数转换十六进制数
#include <stdio.h>
int main(void)
{
    unsigned int num = 0;
    unsigned int mask = 0x0f;
    unsigned int i = 0;
    unsigned int move = 28;
    char str[16] = "0123456789abcdef";
    printf("input a number:");
    scanf("%d",&num);
    printf("0x");

    for (; i<8; i++)  
    {
        printf("%c",str[((num >> move) & mask)]);
        move -= 4;
    }
    printf("\n");

    return 0;
}
