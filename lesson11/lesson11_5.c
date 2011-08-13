//输入一个十进制数转化成2进制数
#include <stdio.h>
int main(void)
{
    int i;
    int ste[100];
    int num;
    printf("input number:");
    scanf("%d",&num);
 
    for(i=0;num!=0;i++)
    {
        ste[i]=num%2;
        num=num/2;
    }
    for(i=i-1;i>=0;i--)
    {
        printf("%d",ste[i]);
    }
    printf("\n");
    return 0;
}

