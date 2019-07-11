#include "fdf.h"

static void set_point_to_addr(t_fdf *fdf)
{
	int ct;
	if (fdf->map.e_point.x >= 0 && fdf->map.e_point.x < WIDTH
		&& fdf->map.e_point.y >= 0 && fdf->map.e_point.y < HEIGHT)
	{
		ct = (fdf->map.e_point.x * (fdf->bts_pr_pxl / 8)) +
		(fdf->map.e_point.y * fdf->sz_ln);
		fdf->data_addr[ct] = fdf->map.point->color;
		fdf->data_addr[++ct] = fdf->map.point->color >> 8;
		fdf->data_addr[++ct] = fdf->map.point->color >> 16;
		fdf->data_addr[++ct] = 0;
	}
}

// static void ft_draw_line(t_fdf *fdf) //bresenham algo
// {
// 	int dx;
// 	int dy;
// 	double f;
// 	double f1;
//
// 	//dx = x1 - x0;
// 	//dy = y1 - y0;
// 	//x > y ? f = dx / 2 : f = dy / 2;
// 	f1 = f - not prim (dx or dy);
// 	if (0 > f1)
// 		put not prim pxl;
// 		f1 = f1 + prim (dx or dy) - not prim (dx or dy);
// 	else
// 		put prim pxl;
// 	f1 = f1 - not prim (dx or dy);
// }

static void ft_draw_line(t_fdf *fdf) //bresenham algo
{
	t_drw_ln helper;

	
}

void ft_draw(t_fdf *fdf)
{
	ft_bzero(fdf->data_addr, (WIDTH * fdf->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(fdf->mlx, fdf->win);
	while (fdf->map.point->prev)
		fdf->map.point = fdf->map.point->prev;
	while(fdf->map.point)
	{
		converter(fdf);
		//ft_draw_line(fdf);
		set_point_to_addr(fdf);
		if (fdf->map.point->next)
			fdf->map.point = fdf->map.point->next;
		else
			break;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
