#include "fdf.h"

static int x_close(void *param)
{
	(void)param;
	exit(0);
}

int key_controls(int key, t_fdf *fdf)
{
	if (key == KB_NUM_PLUS || key == KB_NUM_MINUS ||
	key == KB_STD_PLUS || key == KB_STD_MINUS)
		zoom(key, fdf);
	else if (key == KB_KEY_RIGHT || key == KB_KEY_LEFT ||
		key == KB_KEY_UP || key == KB_KEY_DOWN)
		move(key, fdf);
	else if (key == KB_KEY_I || key == KB_KEY_P)
		change_projection(key, fdf);
	else if (key == KB_KEY_Z_PLS || key == KB_KEY_Z_MNS)
		change_z(key, fdf);
	else if (key == KB_KEY_ARR_RIGHT || key == KB_KEY_ARR_LEFT)
		change_color(key, fdf);
	return (0);
}

int mouse_controls_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == MS_SCRL_UP || button == MS_SCRL_DWN)
		zoom(button, fdf);
	if (button == MS_LFT_BTN || button == MS_RGHT_BTN)
		key_press(button, x, y, fdf, YES);
	return (0);
}

int mouse_controls_release(int button, int x, int y, t_fdf *fdf)
{
	if (button == MS_LFT_BTN || button == MS_RGHT_BTN)
	{
		key_press(button, x, y, fdf, NO);
	}
	return (0);
}

int mouse_controls_move(int x, int y, t_fdf *fdf)
{
	if (fdf->cntrls->lft_prssd)
		mouse_move(x, y, fdf);
	return (0);
}

void init_key_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 0, x_close, fdf);
	mlx_hook(fdf->win, 2, 0, key_controls, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_controls_press, fdf); //mouse_press
	mlx_hook(fdf->win, 5, 0, mouse_controls_release, fdf); // mouse_release
	mlx_hook(fdf->win, 6, 0, mouse_controls_move, fdf); // mouse_rmove SEGFLT(?)
}
