#ifndef	_FUNC_H_
#define	_FUNC_H_

typedef unsigned char u8_t;
typedef unsigned int u32_t;

#define	ST_X	100
#define	ST_Y	40
#define SPACE	30

#define	X_NUM	29
#define	Y_NUM	24

#define	BLACK	0x00000000
#define WHITE	0x00ffffff
#define	YELLOW	0x00cc9966
typedef struct
{
	int w; //宽
	int h; //高
	int bpp; //分辨率

	void *memo; //指向内存的指针
} fbscr_t;

typedef struct
{
	int dx;
	int dy; //鼠标移动
	char button;//鼠标值
} mouse_event;

int init_data( void );
int fb_one_pixel(int x, int y, u32_t color);
int fb_line(int x1, int y1, int x2, int y2, u32_t color);
int fb_circle(int x0, int y0, int r, u32_t color);
void print_board(void);
int draw_cursor(int x, int y);
int save_bg(int x, int y);
int restore_bg(int x, int y);
int mouse_doing(void);
int chess_doing(void);
#endif
