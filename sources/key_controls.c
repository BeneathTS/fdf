#include "fdf.h"

int zoom(int key, t_fdf *fdf)
{
	if (key == KB_NUM_PLUS ||
		key == KB_STD_PLUS)
		fdf->cam.zoom++;
	else if (key == KB_NUM_MINUS ||
		key == KB_STD_MINUS)
		fdf->cam.zoom--;
	if (fdf->cam.zoom < 1)
		fdf->cam.zoom = 1;
	ft_draw(fdf);
	return (0);
}

int move(int key, t_fdf *fdf)
{
	if (key == KB_ARR_LEFT)
		fdf->cam.x_offset -= 15;
	if (key == KB_ARR_RIGHT)
		fdf->cam.x_offset += 15;
	if (key == KB_ARR_UP)
		fdf->cam.y_offset -= 15;
	if (key == KB_ARR_DOWN)
		fdf->cam.y_offset += 15;
	ft_draw(fdf);
	return (0);
}
