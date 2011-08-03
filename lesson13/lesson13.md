akaedu@akaedu-desktop:~/work/C_stage/lesson13$ gcc -Wall lesson13_6.c
akaedu@akaedu-desktop:~/work/C_stage/lesson13$ ./a.out 
1 parameters:
./a.out
akaedu@akaedu-desktop:~/work/C_stage/lesson13$ ./a.out x y l
4 parameters:
./a.out
x
y
l

#include <stdio.h>
int main(int argc, const char *argv[])
{
    int i = 0;

    printf("%d parameters:\n",argc);
    for (i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
                     
    //    printf("hello ,world\n");
    return 0;
}
