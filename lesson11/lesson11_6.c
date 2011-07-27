#include <stdio.h>
int main(int argc, const char *argv[])
{
    unsigned int num;
    unsigned int mask = (1<<31);
    printf("输入一个数：");
    scanf("%d",&num);

    for (; mask > 0; mask >>= 1) //(i=0; i<32; i++) 
    {
        printf("%c",((num & mask) > 0) ? '1' : '0');      
   //     mask >>= 1;
    }
    printf("\n");

    return 0;
}
