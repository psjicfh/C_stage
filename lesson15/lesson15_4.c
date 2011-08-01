#include <stdio.h>
#define N 20

int main(int argc, const char *argv[])
{
    int str[N] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
//    int flag = 0;
    int i;
    for (i = 0; i < N-1; i++) 
    {
        if(str[i] != str[i+1]) 
        {
            printf("%d",str[i]);
            if (i == (N-1)) 
            {
                printf("%d\n",str[N-1]);
                break;
            }
        }
       /* if (flag == 1) {
            
        }*/
    }
    printf("\n");

    return 0;
}
