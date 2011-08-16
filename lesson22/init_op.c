#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include "func.h"
#include <string.h>

fbscr_t fb_v;

int init_data(void)
{
	int fd = 0;
	struct fb_var_screeninfo fb_var; //在头文件linux/fb.h中定义

	fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) 
	{
		perror("open fb0");
		exit(0);
	}
	if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_var) < 0) 
	{
		perror("ioctl");
		exit(0);
	}
	
	printf("w=%d\th=%d\tbpp=%d\n", fb_var.xres,fb_var.yres,fb_var.bits_per_pixel);
	
	fb_v.w = fb_var.xres;
	fb_v.h = fb_var.yres;
	fb_v.bpp = fb_var.bits_per_pixel;

	fb_v.memo = mmap(NULL, fb_v.w*fb_v.h*fb_v.bpp/8, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(fb_v.memo == MAP_FAILED) //检查是否映射成功
	{
		perror("map");
		exit(0);
	}
	memset(fb_v.memo, 0, fb_v.w*fb_v.h*fb_v.bpp/8); //清屏
//	while(1);
/*	int i,j;
	u32_t *p = fb_v.memo;
	for (i = 1024*300; i < fb_v.w*500; i++) 
	{
		p[i] = 0x00ff0000;
		//p[i] = 0x00ff0000;
	}
	for (i = 0; i < fb_v.h; i++) {
		p[i*1024] = 0x00ff0000;
	}*/

	return 0;
}
