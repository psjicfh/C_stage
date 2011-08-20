#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <sys/mman.h>

#include "func.h"



fbscr_t fb_v;

int mx;
int my; //光标位置

char chess_board[X_NUM*Y_NUM]; //棋盘大小数组
char player; //玩儿家 
u32_t current_color; //颜色

int init_data(void)
{	
	int fd = 0;
	struct fb_var_screeninfo fb_var;
	//在头文件/usr/include/linux/fb.h
	fd = open("/dev/fb0", O_RDWR); //打开设备文件
	if(fd < 0)
	{
		perror("open fb0");
		exit(0);
	}

	if(ioctl(fd, FBIOGET_VSCREENINFO,&fb_var) < 0)
	{
		perror("ioctl");
		exit(0);
	}
	
	fb_v.w = fb_var.xres;
	fb_v.h = fb_var.yres;
	fb_v.bpp = fb_var.bits_per_pixel;

	fb_v.memo = mmap(NULL, fb_v.w*fb_v.h*fb_v.bpp/8, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	//详见笔记	
	if(fb_v.memo == MAP_FAILED) //检查内存是否映射成功
	{
		perror("map");
		exit(0);
	}
	memset(fb_v.memo, 0, fb_v.w*fb_v.h*fb_v.bpp/8); //清屏
	memset(chess_board, 0, X_NUM*Y_NUM); //清棋盘

	current_color = BLACK;
	player = 1;

	return 0;
}

