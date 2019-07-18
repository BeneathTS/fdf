#include "fdf.h"

void iso(int *x, int *y, int z)
{
	int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void converter(t_fdf *fdf, t_e_point *e_point, int x, int y)
{
	e_point->x = x * fdf->cam->zoom;
    e_point->y = y * fdf->cam->zoom;
	e_point->z = fdf->map->coords[y][x].z * fdf->cam->zoom / fdf->cam->z_offset;
	if (fdf->cam->prj == ISO)
		iso(&e_point->x, &e_point->y, e_point->z);
	e_point->x += fdf->cam->x_offset;
	e_point->y += fdf->cam->y_offset;
}
