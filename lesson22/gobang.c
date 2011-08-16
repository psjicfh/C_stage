#include <stdio.h>
#include "func.h"
#include "varfous.h"

int main(int argc, const char *argv[])
{
	init_data();
/*	int i,j;

	for (j = 0; j < 100; j++) 
	{
		for (i = 0; i < 100; i++) 
		{
			fb_one_pixel(500+i, 300+j, 0x00ff0000);			
		}
	}*/
	fb_line(0, 0, fb_v.w-1, fb_v.h-1, 0x000000ff);
	fb_line(300, 500, 310, 200, 0xf00000ff);
	fb_line(1023, 0, 0, fb_v.h-1, 0x000000ff);

    return 0;
}
