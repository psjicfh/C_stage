#include <stdio.h>
#include "various.h"

void print_board(void)
{
	int i = 0;

	for(i = 0; i < Y_NUM; i++)
	{
		fb_line(ST_X, ST_Y+i*SPACE,ST_X+(X_NUM-1)*SPACE ,ST_Y+i*SPACE, 0x0000ff00);
	}

	for(i = 0; i < X_NUM; i++)
	{
		fb_line(ST_X+i*SPACE, ST_Y, ST_X+i*SPACE, ST_Y+(Y_NUM-1)*SPACE, 0x0000ff00);	
	}
}
