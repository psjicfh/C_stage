#include <stdio.h>
#include <unistd.h>
#include "func.h"
#include "various.h"

int main(void)
{
	init_data();
	print_board();
	mouse_doing();
	return 0;
}
