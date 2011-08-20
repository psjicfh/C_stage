#include <stdio.h>
#include "various.h"

int check(int x, int y)
{
	char who = chess_board[x+y*X_NUM];
	int i = 0;
	int j = 0;
	int counter = 1;

	if(who == 0)
	{
		return 0;
	}

	for(i=1; i<5; i++)
	{
		if(chess_board[x+i+y*X_NUM] == who)
		{
			counter++;		
		}
		else
		{
			break;
		}
	}
	if(counter == 5)
	{
		return who;
	}
	counter = 1;
	for(i=1, j= -1; i<5; i++, j--)
	{
		if(chess_board[x+i+(y+j)*X_NUM] == who)
		{
			counter++;		
		}
		else
		{
			break;
		}
	}
	if(counter == 5)
	{
		return who;
	}

	return 0;
}

int chess_put(int x, int y)
{
	int i = 0;
	int j = 0;
	int winner = 0;
	chess_board[x+y*X_NUM] = player;
	
	for(j=0; j<Y_NUM; j++)
	{
		for(i=0; i<X_NUM; i++)
		{
			if((winner = check(i, j)) > 0)
			{
				return winner;
			}
		}
	}

	return 0;
}

int chess_doing(void)
{
	int rx = (mx-ST_X)%SPACE;
	int ry = (my-ST_Y)%SPACE;
	int cx = mx - rx;
	int cy = my - ry;

	if((mx < ST_X) || (mx > (ST_X+(X_NUM-1)*SPACE)))
	{
		return 0;
	}
	if((my < ST_Y) || (my > (ST_Y+(Y_NUM-1)*SPACE)))
	{
		return 0;
	}
	if(rx > (SPACE/2))
	{
		cx += SPACE;	
	}
	if(ry > (SPACE/2))
	{
		cy += SPACE;
	}
	char winner = 0;
	fb_circle(cx, cy, 13, current_color);
	winner = chess_put((cx-ST_X)/SPACE, (cy-ST_Y)/SPACE);
	if(winner > 0 )
	{
		return winner;
	}
	if(current_color == WHITE)
	{
		current_color = BLACK;
		player = 1;
	}
	else
	{
		current_color = WHITE;
		player = 2;
	}

	return 0;
}
