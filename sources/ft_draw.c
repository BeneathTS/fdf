#include "fdf.h"

/*static void ft_draw_line()
{

}*/

static void set_point_to_addr(t_fdf *fdf, int x, int y)
{
	int ct;

	ct = (x * (fdf->bts_pr_pxl / 8)) + (y * fdf->sz_ln);
	fdf->data_addr[ct] = fdf->map.point->color;
	fdf->data_addr[++ct] = fdf->map.point->color >> 8;
	fdf->data_addr[++ct] = fdf->map.point->color >> 16;
	fdf->data_addr[++ct] = 0;
}

void ft_draw(t_fdf *fdf)
{
	set_point_to_addr(fdf, 250, 250);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
