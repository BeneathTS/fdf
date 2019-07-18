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

static void bresenham_algo(t_fdf *fdf, t_e_point s, t_e_point f, int x,  int y)
{
	t_e_point d;
	t_e_point sgn;
	int		err[2];

	d.x = ft_abs(f.x - s.x);
	d.y = ft_abs(f.y - s.y);
	sgn.x = 0 < (f.x - s.x) ? 1 : -1;
	sgn.y = 0 < (f.y - s.y) ? 1 : -1;
	err[0] = d.x - d.y;
	while (s.x != f.x || s.y != f.y)
	{
		set_point_to_addr(fdf, s.x, s.y, x, y);
		if ((err[1] = 2 * err[0]) > -d.y)
		{
			s.x += sgn.x;
			err[0] -= d.y;
		}
		if (err[1] < d.x)
		{
			s.y += sgn.y;
			err[0] += d.x;
		}
	}
}

static void ft_draw_map(t_fdf *fdf)
{
	if (fdf->draw->x + 1 < fdf->map->width)
	{
		converter(fdf, &fdf->draw->strt ,fdf->draw->x, fdf->draw->y);
		converter(fdf, &fdf->draw->fnsh, fdf->draw->x + 1, fdf->draw->y);
		bresenham_algo(fdf, fdf->draw->strt, fdf->draw->fnsh, fdf->draw->x, fdf->draw->y);
	}
	if (fdf->draw->y + 1 < fdf->map->height)
	{
		converter(fdf, &fdf->draw->strt ,fdf->draw->x, fdf->draw->y);
		converter(fdf, &fdf->draw->fnsh, fdf->draw->x, fdf->draw->y + 1);
		bresenham_algo(fdf, fdf->draw->strt, fdf->draw->fnsh, fdf->draw->x, fdf->draw->y);
	}
}

void ft_draw(t_fdf *fdf)
{
	ft_bzero(fdf->data_addr, (WIDTH * fdf->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(fdf->mlx, fdf->win);

	fdf->draw->y = -1;
	while (++fdf->draw->y < fdf->map->height)
	{
		fdf->draw->x = -1;
		while (++fdf->draw->x < fdf->map->width)
		{
			ft_draw_map(fdf);
		}
	}

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
