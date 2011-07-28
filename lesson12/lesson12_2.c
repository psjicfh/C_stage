#include <stdio.h>

int add(int a,int b)
{
    a += 1; 
    return (a+b);
}

int main(int argc, const char *argv[])
{
    int a = 5;
    int b = 6;
     
    int c = add(a,b);
    printf("c = %d,a = %d\n",c,a);

    return 0;
}
