#include "fdf.h"

void key_press(int button, int x, int y, t_fdf *fdf, char flag)
{
	if (button == MS_LFT_BTN)
		fdf->cntrls->lft_prssd = flag;
	if (button == MS_RGHT_BTN)
		fdf->cntrls->rght_prssd = flag;
	fdf->cntrls->strt_x = x;
	fdf->cntrls->strt_y = y;
	fdf->cntrls->prev_x = 0;
	fdf->cntrls->prev_y = 0;
}

void mouse_move(int x, int y, t_fdf *fdf)
{
	fdf->cam->x_offset -= fdf->cntrls->strt_x - x - fdf->cntrls->prev_x;
	fdf->cam->y_offset -= fdf->cntrls->strt_y - y - fdf->cntrls->prev_y;

	fdf->cntrls->prev_x = fdf->cntrls->strt_x - x;
	fdf->cntrls->prev_y = fdf->cntrls->strt_y - y;
	ft_draw(fdf);
}
