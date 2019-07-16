#include "fdf.h"

static void set_point_to_addr(t_fdf *fdf, int e_x, int e_y, int x, int y)
{
	int ct;

	if (e_x >= 0 && e_x < WIDTH && e_y >= 0 && e_y < HEIGHT)
	{
		ct = (e_x * (fdf->bts_pr_pxl / 8)) + (e_y * fdf->sz_ln);
		fdf->data_addr[ct] = fdf->map->coords[y][x].color;
		fdf->data_addr[++ct] = fdf->map->coords[y][x].color >> 8;
		fdf->data_addr[++ct] = fdf->map->coords[y][x].color >> 16;
		fdf->data_addr[++ct] = 0;
	}
}

// static void ft_draw_line(t_fdf *fdf, int x, int y) //bresenham algo
// {
// 	t_e_point strt;
// 	t_e_point fnsh;
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

static void bresenham_algo(t_fdf *fdf, t_e_point s, t_e_point f)
{
	fdf->draw->dx = f.x - s.x;
	fdf->draw->dy =	f.y - s.y;
	fdf->draw->prm = f.y >= f.x ? fdf->draw->dy : fdf->draw->dx;
	fdf->draw->nt_prm = f.y >= f.x ? fdf->draw->dx : fdf->draw->dy;
	fdf->draw->f[0] = fdf->draw->prm / 2;
	fdf->draw->f[1] = fdf->draw->f[0] - fdf->draw->nt_prm;
	set_point_to_addr(fdf, s.x, s.y, fdf->draw->x, fdf->draw->y);
	while (s.x < f.x && s.y < f.y)
	{
		
	}
}

static void ft_draw_map(t_fdf *fdf)
{
	fdf->draw->strt = converter(fdf, fdf->draw->x, fdf->draw->y);
	if (fdf->draw->x + 1 <= fdf->map->width)
	{
	 	fdf->draw->fnsh = converter(fdf, fdf->draw->x + 1, fdf->draw->y);
		bresenham_algo(fdf, *fdf->draw->strt, *fdf->draw->fnsh);
	}
	if (fdf->draw->y + 1 < fdf->map->height)
	{
		fdf->draw->fnsh = converter(fdf, fdf->draw->x, fdf->draw->y + 1);
		bresenham_algo(fdf, *fdf->draw->strt, *fdf->draw->fnsh);
	}
}

void ft_draw(t_fdf *fdf)
{

	ft_bzero(fdf->data_addr, (WIDTH * fdf->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(fdf->mlx, fdf->win);

	fdf->draw->y = -1;
	printf("w: %d\nh: %d\n\n", fdf->map->width, fdf->map->height);
	while (++fdf->draw->y < fdf->map->height)
	{
		printf("y: %d\n", fdf->draw->y);
		fdf->draw->x = -1;
		while (++fdf->draw->x < fdf->map->width)
		{
			printf("x: %d\n", fdf->draw->x);
			ft_draw_map(fdf);
		}
	}

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
