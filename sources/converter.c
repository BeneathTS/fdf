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

t_e_point *converter(t_fdf *fdf, int x, int y)
{
	t_e_point *e_point;

	e_point = (t_e_point*)malloc(sizeof(t_e_point));
	e_point->x = x * fdf->cam->zoom;
    e_point->y = y * fdf->cam->zoom;
	if (fdf->cam->prj == ISO)
		iso(&e_point->x, &e_point->y, fdf->map->coords[y][x].z);
	e_point->x += fdf->cam->x_offset;
	e_point->y += fdf->cam->y_offset;
	if (fdf->cam->prj != PARAL)
	{
	 	if (fdf->map->coords[y][x].z > 0)
	 		e_point->y -= ft_abs(fdf->map->coords[y][x].z) * fdf->cam->z_offset;
	 	else if (fdf->map->coords[y][x].z < 0)
	 		e_point->y += ft_abs(fdf->map->coords[y][x].z) * fdf->cam->z_offset;
	}
	return (e_point);
}
