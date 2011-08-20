#include <stdio.h>
#include "varfous.h"

int chess_doing(void)
{
	int	rx = (mx-ST_X) % SPACE;
	int	ry = (my-ST_Y) % SPACE;
	int cx = mx - rx;
	int cy = my - ry;

	if ((mx < ST_X) || (mx > (ST_X+(X_NUM-1)*SPACE))) 
	{
		return 0;
	}

	if ((my < ST_Y) || (my > (ST_Y+(Y_NUM-1)*SPACE))) 
	{
		return 0;
	}

	if (rx > (SPACE/2)) 
	{
		cx += SPACE;
	}

	if (ry > (SPACE/2)) 
	{
		cy += SPACE;
	}
	
	fb_circle(cx, cy, 13, 0x00ff0000);

	return 0;
}
