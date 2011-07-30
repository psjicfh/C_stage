#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	M	5

void print_array(int *p, int n)
{
	int i = 0;

	for(i=0; i<n; i++)
	{
		if((i%9) == 0)
		{
			printf("\n");
		}
		printf("%6d", p[i]);
	}
	printf("\n");
}

void init_array(int *p, int n)
{
	srand(time(NULL));//种子

	int i = 0;

	for(i=0; i<n; i++)
	{
		p[i] = rand()%(n*2);
	}
}

/*void sort_array(int *p, int n)
{
	int i = 0;
	int j = 0;
	int temp;

	for(i=0; i<(n-1); i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}*/

void sort_array(int *p, int n)
{
    int i = 0;
    int j = 0;
    int temp;
    int k = 0;

    for(i=0; i<(n-1); i++)
    {
        k = i;
        for (j = i+1; j < n; j++) 
        {
            if (p[k]>p[j]) 
            {
                k = j;
            }
        }
        if(i != k)
        {
            temp = p[i];
            p[i] = p[k];
            p[k] = temp;
        }   
    }   
}

int main(int argc,  char *argv[])
{
	int array[M];

	init_array(array, M);
	print_array(array, M);
	sort_array(array, M);
	print_array(array, M);
	
    return 0;
} 
