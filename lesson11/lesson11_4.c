#include <stdio.h>
#define uint unsigned int
int main(void)
{
    uint a = 0xaa;
    uint b = 0x1e; //要取出倒数第2到5位即0101
    uint c = 0;
    c = (a & b);
    c >>= 1;
    printf("%d\n",c);

    return 0;
}
