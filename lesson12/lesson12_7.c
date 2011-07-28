#include <stdio.h>
#define N 10
int main(int argc, const char *argv[])
{
//    int a = 9;
//    int b = 0;
    int c[N];
    int i;
//    int *ptr = &a; //指针变量ptr指向a的地址
    int *ptr = c;  //指针变量ptr指向数组c的首地址
    //上句分开后 int = *ptr;  ptr = c;
//    printf("a = %x\n",a);
//    printf("&a = %x\n",&a);
//    printf("ptr = %x\n",ptr);
//    printf("*ptr = %x\n",*ptr);
//    printf("&ptr = %x\n",&ptr);
    
    for (i = 0; i < N; i++,ptr++) 
    {
        *ptr = i+1;
        printf("%4d", c[i]);
    }
    printf("\n");
    return 0;
}
