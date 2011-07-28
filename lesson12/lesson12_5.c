#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int array[100];
/*    for (i = 0; i < 100; i++) 
    {
        printf("%4d",array[i] = i+1);
        if(i%10 == 9)
        {
            printf("\n");
        }
    }  

    while (i < 100) 
    {
        printf("%4d",array[i] = i+1);
        if(i%10 == 9)
        {
            printf("\n");
        }
        i++;
    }*/ 

    do
    {
        printf("%4d",array[i] = i+1);
        if(i%10 == 9)
        {
            printf("\n");
        }
        i++;
    } while (i <100); //注意此处“;”
    
    return 0;
}
