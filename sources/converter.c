#include "fdf.h"

void iso(t_fdf *fdf, int x, int y)
{
	int previous_x;
    int previous_y;

    previous_x = x;
    previous_y = y;
    fdf->map.e_point.x = (previous_x - previous_y) * cos(0.523599);
    fdf->map.e_point.y = (previous_x + previous_y) * sin(0.523599);
}

int converter(int x, int y, t_fdf *fdf)
{
	fdf->map.e_point.x = x * fdf->cam.zoom;
    fdf->map.e_point.y = y * fdf->cam.zoom;
	if (fdf->cam.prj == ISO)
		iso(fdf, fdf->map.e_point.x, fdf->map.e_point.y);
	fdf->map.e_point.x += fdf->cam.x_offset;
	fdf->map.e_point.y += fdf->cam.y_offset;
	return (0);
}
