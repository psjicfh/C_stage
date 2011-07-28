#include <stdio.h>
int main(void)
{   
    int j;
    for (j = 1; j <= 100; j++)
    {
        printf("%-4d",j);//左对齐- ，右对齐 + 4代表宽度
        if(j%10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
