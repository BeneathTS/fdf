#include "fdf.h"

int zoom(int key, t_fdf *fdf)
{
	if (key == KB_NUM_PLUS ||
		key == KB_STD_PLUS)
		fdf->cam->zoom++;
	else if (key == KB_NUM_MINUS ||
		key == KB_STD_MINUS)
		fdf->cam->zoom--;
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	ft_draw(fdf);
	return (0);
}

int move(int key, t_fdf *fdf)
{
	if (key == KB_KEY_LEFT)
		fdf->cam->x_offset -= 15;
	else if (key == KB_KEY_RIGHT)
		fdf->cam->x_offset += 15;
	else if (key == KB_KEY_UP)
		fdf->cam->y_offset -= 15;
	else if (key == KB_KEY_DOWN)
		fdf->cam->y_offset += 15;
	ft_draw(fdf);
	return (0);
}

int change_projection(int key, t_fdf *fdf)
{
	if (key == KB_KEY_I)
		fdf->cam->prj = ISO;
	else if (key == KB_KEY_P)
		fdf->cam->prj = PARAL;
	ft_draw(fdf);
	return (0);
}

int change_z(int key, t_fdf *fdf)
{
	if (key == KB_KEY_Z_PLS)
		fdf->cam->z_offset++;
	else if (key == KB_KEY_Z_MNS)
		fdf->cam->z_offset--;
	ft_draw(fdf);
	return (0);
}

// int change_color(int key, t_fdf *fdf)
// {
// 	if (key == KB_KEY_ARR_RIGHT)
// 		fdf->cam->std_color++;
// 	else if (key == KB_KEY_ARR_LEFT)
// 		fdf->cam->std_color--;
// 	ft_draw(fdf);
// 	return(0);
// }
