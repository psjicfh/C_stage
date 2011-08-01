#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	M	9

void print_array(int *p, int n)
{
	int i = 0;

	for(i=0; i<n; i++)
	{
		if((i%9) == 0)
		{
			printf("\n");
		}
		printf("%7d", p[i]);
	}
	printf("\n");
}

void init_array(int *p, int n)
{
	srand(time(NULL));

	int i = 0;

	for(i=0; i<n; i++)
	{
		p[i] = rand()%(n*2);
	}
}

void delete_num(int *p, int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < n-1; i++) 
    {
        if(p[i] != -1)
        {
            for (j = i+1; j < n; j++) 
            {
                if (p[i] == p[j]) 
                {
                    p[j] = -1;
                }
            }
        }
    }
}

void print_simplify(int *p,int n)
{
	int i = 0;

	for(i=0; i<n; i++)
	{
        if(p[i] != -1)
        {
            if((i%8) == 0)
            {
                printf("\n");
            }
            printf("%7d", p[i]);
        }
	}
	printf("\n");        
}

int main(int argc,  char *argv[])
{
	int array[M];
	init_array(array, M);
printf("original:\n");
	print_array(array, M);
printf("press enter to start...");	
getchar();
//	sort_array(array, M);
//	quick_sort(array, 0, M-1);
printf("finished.\n");	
getchar();	
printf("output:\n");
//	print_array(array, M);
delete_num(array, M);
print_array(array, M);
print_simplify(array, M);
	return 0;
} 

