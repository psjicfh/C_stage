#include <stdio.h>
//递归调用函数 汉诺塔游戏

void hanio(char a, char b, char c, int n)
{
    if (n == 1) 
    {
        printf("%c----->%c\n",a,c);
        return; //没此句就断错误 作用是结束函数而不是结束循环语句
    }
    hanio(a,c,b,n-1); //a通过c把n-1个盘子放在b上
    printf("%c----->%c\n",a,c);
    hanio(b,a,c,n-1);
}

int main(int argc, const char *argv[])
{
    int n = 3;
    hanio('A','B','C',n); //ABC三根杆儿 A上有n个盘子

    return 0;
}
