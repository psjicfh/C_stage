#include <stdio.h>
#include "func.h"
#include <unistd.h>
#include "varfous.h"

int main(int argc, const char *argv[])
{
	init_data();

	int i;
	for (i = 0; i < Y_NUM; i++) 
	{
		fb_line(ST_X, ST_Y+i*SPACE, ST_X+(X_NUM-1)*SPACE, ST_Y+i*SPACE, 0xf000ff00);	
	}

	for (i = 0; i < X_NUM; i++) 
	{
		fb_line(ST_X+i*SPACE, ST_Y, ST_X+i*SPACE, ST_Y+(Y_NUM-1)*SPACE, 0xf000ff00);	
	}

	fb_circle(ST_X+(X_NUM-1)/2*SPACE, ST_Y+(Y_NUM-1)/2*SPACE, 13, 0x00ff0000);
	fb_circle(ST_X+(X_NUM-3)/2*SPACE, ST_Y+(Y_NUM+3)/2*SPACE, 13, 0x000000ff);
	
//	save_bg(512,384);
/*	draw_cursor(512,384);
	sleep(1);
	restore_bg(512,384);
	draw_cursor(512,300);*/
	mouse_doing();

    return 0;
}
