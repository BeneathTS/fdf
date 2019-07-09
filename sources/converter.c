#include "fdf.h"

void iso(t_fdf *fdf, int x, int y)
{
	int previous_x;
    int previous_y;

    previous_x = x;
    previous_y = y;
    fdf->map.e_point.x = (previous_x - previous_y) * cos(0.523599);
    fdf->map.e_point.y = -fdf->map.point->z + (previous_x + previous_y) * sin(0.523599);
}

int converter(int x, int y, t_fdf *fdf)
{
	return (0);
}
