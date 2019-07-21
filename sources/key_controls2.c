#include "fdf.h"

void rotate(int key, t_fdf *fdf)
{
	if (key == KB_NUM_5)
		fdf->cam->angle_x += 0.05;
	if (key == KB_NUM_8)
		fdf->cam->angle_x -= 0.05;
	if (key == KB_NUM_4)
		fdf->cam->angle_y += 0.05;
	if (key == KB_NUM_6)
		fdf->cam->angle_y -= 0.05;
	if (key ==  KB_NUM_9)
		fdf->cam->angle_z += 0.05;
	if (key ==  KB_NUM_7)
		fdf->cam->angle_z -= 0.05;
	ft_draw(fdf);
}
