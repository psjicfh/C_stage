#include <stdio.h>
//#define 

int main(int argc, const char *argv[])
{
    int i,j,temp;
    int a[] = {6,5,3,4,8,7,9,1,2,0};
/*    for (i = 0; i < 10; i++) 
    {
        a[i] = i;
        printf("%4d",a[i]);
    }
    printf("\n");
*/  for (j = 0; j < 9; j++)
    {
        for (i = j+1; i < 10; i++) 
        {   
            if (a[j] > a[i]) 
            {
                temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp; 
            }
        }
    }
    
    for (i = 0; i < 10; i++)
    {
        printf("%4d",a[i] );
    }
    printf("\n");
    return 0;
}
