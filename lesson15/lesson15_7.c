#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	N	8
#define	M	10
//二维数组赋初值
int main(void)
{
	int array[M][N];
	int i = 0;
	int j = 0;
//    int *p = array; 这样会有警告
    int (*p)[N] = array;
//    p = array;

//printf("&array[0][0]: %x\n",&array[0][0]); //&array[0][0]: bfe22178
            //"%p"打印地址，"%x"打印地址的16进制数
printf("&array[0][0]: %p\n",&array[0][0]);
printf("array：       %p\n",array);        //array：     0xbfe22178
printf("&array[0]：   %p\n",&array[0]);
printf("array[0]：    %p\n",array[0]);
printf("&array[1][0]： %p\n",&array[1][0]); //&array[1][0]： 0xbf8092d4 变了

	for(j=0; j<M; j++)
	{
		for(i=0; i<N; i++)
		{
			array[j][i] = rand()%(M*N);
		}
	}
	
	for(j=0; j<M; j++)
	{
		for(i=0; i<N; i++)
		{
			printf("%4d",array[j][i]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
