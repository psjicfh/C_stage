#include <stdio.h>
#include "various.h"

void print_board(void)
{
	int i = 0;
	int j = 0;
	for(j=ST_Y-20; j<Y_NUM*SPACE+30; j++)
	{
		for(i=ST_X-80; i<X_NUM*SPACE+SPACE*2+50; i++)
		{
			fb_one_pixel(i, j, YELLOW);
		}
	}
	for(i = 0; i < Y_NUM; i++)
	{
		fb_line(ST_X, ST_Y+i*SPACE,ST_X+(X_NUM-1)*SPACE ,ST_Y+i*SPACE, BLACK);
	}

	for(i = 0; i < X_NUM; i++)
	{
		fb_line(ST_X+i*SPACE, ST_Y, ST_X+i*SPACE, ST_Y+(Y_NUM-1)*SPACE, BLACK);	
	}
}
