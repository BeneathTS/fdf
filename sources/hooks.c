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
	// else if (key == KB_KEY_ARR_RIGHT || key == KB_KEY_ARR_LEFT)
	// 	change_color(key, fdf);
	return (0);
}

void init_key_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 0, x_close, fdf);
	mlx_hook(fdf->win, 2, 0, key_controls, fdf);
}
