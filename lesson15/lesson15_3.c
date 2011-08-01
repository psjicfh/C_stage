#include <stdio.h>
#define N 100
//在 0～99 中找到9的个数
int main(int argc, const char *argv[])
{
    int i,num = 0;
    int str[N];
    for (i = 0; i < N; i++) 
    {
        printf("%4d",str[i] = i);    
        if((i+1)%10 == 0)
        {
            printf("\n");
        }

        if ((str[i] % 10 == 9))     
        {
            num++;
        }

       /* if (str[i] / 11 == 9) 
        {
            num = num + 2;
        }*/

        if (str[i] / 10 == 9) {
            num++;
        }
    } 
    printf("%d\n",num);

    return 0;
}
