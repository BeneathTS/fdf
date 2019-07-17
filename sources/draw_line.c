#include "fdf.h"

static void bresenham_algo(t_fdf *fdf, t_e_point s, t_e_point f)
{
	fdf->draw->dx = f.x - s.x;
	fdf->draw->dy =	f.y - s.y;
	fdf->draw->prm = f.y >= f.x ? fdf->draw->dy : fdf->draw->dx;
	fdf->draw->nt_prm = f.y >= f.x ? fdf->draw->dx : fdf->draw->dy;
	fdf->draw->f[0] = fdf->draw->prm / 2;
	fdf->draw->f[1] = fdf->draw->f[0] - fdf->draw->nt_prm;
	set_point_to_addr(fdf, s.x, s.y, fdf->draw->x, fdf->draw->y);
	// while (s.x < f.x && s.y < f.y)
	// {
	//
	// }
}
