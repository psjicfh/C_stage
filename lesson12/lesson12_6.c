/* 约瑟夫环*/

#include <stdio.h>
#define uchar unsigned char
#define N  11
int main(int argc, const char *argv[])
{   
    uchar num = 0;
    uchar interval = 3; //隔三个去除一个
    uchar out_counter = 0;
    uchar doom[N] = {0};
    uchar i = 0;

    for (i = 0;num < N; i++)
    {
        if (i == N) 
        {
            i = 0;
        }    
        if (doom[i] == 0) 
        {
        
            if (num == (N-1))
            {
                printf("%4d (left)\n", i+1);
                break; //若无此句则跳不出去
            }

            out_counter++;
            if (out_counter == interval) 
            {
                out_counter = 0;
                doom[i] = 1;
                printf("%4d(out)\n",i+1);
                num++;
            }
            else
            {
                printf("%4d",i+1);   
            }                
        }

    }

    return 0;
}
