#include "fdf.h"

static int x_close(void *param)
{
	(void)param;
	exit(0);
}

int key_controls(int key, t_fdf *fdf)
{
	if ((key == KB_NUM_PLUS || key == KB_NUM_MINUS ||
		key == KB_STD_PLUS || key == KB_STD_MINUS) &&
		fdf->cam->menu == CLOSED)
		zoom(key, fdf);
	if ((key == KB_KEY_RIGHT || key == KB_KEY_LEFT ||
		key == KB_KEY_UP || key == KB_KEY_DOWN) &&
		fdf->cam->menu == CLOSED)
		move(key, fdf);
	if ((key == KB_KEY_I || key == KB_KEY_P) && fdf->cam->menu == CLOSED)
		change_projection(key, fdf);
	if ((key == KB_KEY_Z_PLS || key == KB_KEY_Z_MNS) && fdf->cam->menu == CLOSED)
		change_z(key, fdf);
	if (key == KB_KEY_C && fdf->cam->menu == CLOSED)
		change_color(fdf);
	if ((key == KB_NUM_4 || key == KB_NUM_6 ||
		key == KB_NUM_8 || key == KB_NUM_5 ||
		key == KB_NUM_7 || key == KB_NUM_9) && fdf->cam->menu == CLOSED)
		rotate(key, fdf);
	if ((key == KB_NUM_STR || key == KB_NUM_SLSH) && fdf->cam->menu == CLOSED)
		set_alpha(key, fdf);
	if (key == KB_STD_F1)
		menu(fdf);
	if (key == KB_STD_ESC)
		x_close(fdf);
	return (0);
}

int mouse_controls_press(int button, int x, int y, t_fdf *fdf)
{
	if ((button == MS_SCRL_UP || button == MS_SCRL_DWN) && fdf->cam->menu == CLOSED)
		zoom(button, fdf);
	if ((button == MS_LFT_BTN || button == MS_RGHT_BTN) && fdf->cam->menu == CLOSED)
		key_press(button, x, y, fdf, YES);
	return (0);
}

int mouse_controls_release(int button, int x, int y, t_fdf *fdf)
{
	if (button == MS_LFT_BTN || button == MS_RGHT_BTN)
		key_press(button, x, y, fdf, NO);
	return (0);
}

int mouse_controls_move(int x, int y, t_fdf *fdf)
{
	if (fdf->cntrls->lft_prssd)
		mouse_move(x, y, fdf);
	if (fdf->cntrls->rght_prssd)
		mouse_rotate(x, y, fdf);
	return (0);
}

void init_key_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 0, x_close, fdf);
	mlx_hook(fdf->win, 2, 0, key_controls, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_controls_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_controls_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_controls_move, fdf);
}
