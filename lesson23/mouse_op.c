#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "varfous.h"

#define	BORD	0x00000fff //鼠标边界颜色
#define	X___	0x000fffff //鼠标箭头里面的颜色
#define	T___	0x00000000 //背景颜色

#define	C_W 10
#define	C_H 17
static u32_t cursor_pixel[C_W*C_H]=
{
	BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
	BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
	BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
	BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
	BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,		
	BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
	BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
	BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
	BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
	BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
	BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
	BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
	BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
	BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
	T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
	T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
	T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___
};

u32_t bg[C_H*C_W] = {0}; 

int draw_cursor(int x, int y) //画鼠标
{
	int i = 0;
	int j = 0;

	save_bg(x, y);

	for (j = 0; j < C_H; j++) 
	{
		for (i = 0; i < C_W; i++) 
		{
			fb_one_pixel(x+i, y+j, cursor_pixel[i+j*C_W]);
		}	
	}
	return 0;
}

int save_bg(int x, int y) //保存背景
{
	int i = 0;
	int j = 0;
	
	for (j = 0; j < C_H; j++) 
	{
		for (i = 0; i <C_W; i++) 
		{
			bg[i+j*C_W] = *((u32_t *)fb_v.memo+x+i+(y+j)*fb_v.w);			
		}
	}

	return 0;
}

int restore_bg(int x, int y) //恢复背景
{
	int i = 0;
	int j = 0;

	for (j = 0; j < C_H; j++) 
	{
		for (i = 0; i < C_W; i++) 
		{
			fb_one_pixel(x+i, y+j, bg[i+j*C_W]);
		}
	}
	return 0;
}

int get_mouse_info(int fd, mouse_event *p)
{
	char buf[8];
	int n = 0;

	n = read(fd, buf, 3);
	if (n > 0) 
	{
		p -> dx = buf[1];
		p -> dy = -buf[2];
		p -> button = (buf[0] & 0x07);
	}

	return n;
}

int mouse_doing(void)
{
	int fd = 0;
	mouse_event m_e;

	fd = open("/dev/input/mice", O_RDWR|O_NONBLOCK);
	if (fd == -1) 
	{
		perror("mice");
		exit(0);
	}

	mx = fb_v.w/2;
	my = fb_v.h/2;

	draw_cursor(mx, my);

	while (1) 
	{
		if (get_mouse_info(fd, &m_e) > 0) 
		{
			restore_bg(mx, my);
			mx += m_e.dx;
			my += m_e.dy;
			draw_cursor(mx, my);
		}					
	}

	return 0;
}
