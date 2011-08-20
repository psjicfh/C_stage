#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "various.h"


#define	BORD	0x00000fff
#define	X___	0x000fffff
#define	T___	YELLOW

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

int draw_cursor(int x, int y)
{
	int i = 0;
	int j = 0;

	save_bg(x, y);
	for(j=0; j<C_H; j++)
	{
		for(i=0; i<C_W; i++)
		{
			fb_one_pixel(x+i,y+j,cursor_pixel[i+j*C_W]);
		}
	}
	return 0;
}


int save_bg(int x, int y)
{
	int i = 0;
	int j = 0;

	for(j=0; j<C_H; j++)
	{
		for(i=0; i<C_W; i++)
		{
			bg[i+j*C_W] = *((u32_t *)fb_v.memo+x+i+(y+j)*fb_v.w);
		}
	}
	return 0;
}


int restore_bg(int x, int y)
{
	int i = 0;
	int j = 0;

	for(j=0; j<C_H; j++)
	{
		for(i=0; i<C_W; i++)
		{
			fb_one_pixel(x+i,y+j,bg[i+j*C_W]);
		}
	}
	return 0;
}


int get_mouse_info(int fd, mouse_event *p)
{
	char buf[8];
	int n = 0;
	n = read(fd, buf, 3);
	if(n > 0)
	{
		p->dx = buf[1];
		p->dy = -buf[2];
		p->button = (buf[0] & 0x07);
	}
	
	return n;
}

void reinit(void)
{
	memset(fb_v.memo, 0, fb_v.w*fb_v.h*fb_v.bpp/8);
	print_board();
	memset(chess_board, 0, X_NUM*Y_NUM);
	player = 1;
	current_color = BLACK;
	mx = fb_v.w/2;
	my = fb_v.h/2;

	draw_cursor(mx,my);
}

int mouse_doing(void)
{
	int fd = 0;
	mouse_event m_e;
	char press_do = 0;
	char flag = 0;


	fd = open("/dev/input/mice", O_RDWR|O_NONBLOCK);
	if(fd == -1)
	{
		perror("mice");
		exit(0);
	}

	mx = fb_v.w/2;
	my = fb_v.h/2;

	draw_cursor(mx, my);

	while(1)
	{
		if(get_mouse_info(fd, &m_e) > 0)
		{
			restore_bg(mx, my);
			mx += m_e.dx;
			my += m_e.dy;
			
			if(mx < 0)
			{
				mx = 0;
			}
			if(mx > (fb_v.w-C_W))
			{
				mx = (fb_v.w-C_W);
			}
			if(my < 0)
			{
				my = 0;
			}
			if(my > (fb_v.h-C_H))
			{
				my = (fb_v.h-C_H);
			}

			switch(m_e.button)
			{
				case 0 : 
				if(press_do == 1)
				{
					press_do = 0;
					flag = chess_doing();
				}
				break;
				case 1 : 
				press_do = 1;	break;
				case 2 : break;
				case 4 : break;
				default : break;
			}
			
			draw_cursor(mx, my);

			if(flag > 0)
			{
				printf("player %d won!\n", flag);
				getchar();
				flag = 0;
				reinit();
			}
		}
		usleep(500);
	}
	close(fd);
	return 0;
}










