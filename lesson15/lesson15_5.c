#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	M	30

void print_array(int *p, int n)
{
	int i = 0;

	for(i=0; i<n; i++)
	{
		if((i%8) == 0)
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

void simplify(int *p,int n)
{
    int i = 0,j;
    int temp;
    printf("%d",p[i]);
    for (i = 1; i < n; i++) 
    {
         for (j = i+1; j < n; j++)
         {  
             for(j=i+1; j > 1; j--)
             {
                 if(p[j] == p[i])
                 {
                    temp = 0;
                   
                 }
                 if(p[j] != p[i]) 
                 {
                     temp = 1;
                 }
             }
             if(temp == 1)
             {
                  printf("%d",p[j]);
             }
         }
    }
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
simplify(array, M);
	return 0;
} 
		


