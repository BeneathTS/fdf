/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:25:28 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 21:11:58 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_color(t_fdf *fdf, t_e_point p, t_e_point d, char flag)
{
	int s_color;
	int	f_color;

	s_color = fdf->map->coords[fdf->draw->y][fdf->draw->x]->color == EMPTY ?
	fdf->cam->std_color :
	fdf->map->coords[fdf->draw->y][fdf->draw->x]->color;
	if (flag == X &&
	fdf->map->coords[fdf->draw->y][fdf->draw->x + 1]->color ==
	fdf->map->coords[fdf->draw->y][fdf->draw->x]->color)
		return (s_color);
	else if (flag == Y &&
	fdf->map->coords[fdf->draw->y + 1][fdf->draw->x]->color ==
	fdf->map->coords[fdf->draw->y][fdf->draw->x]->color)
		return (s_color);
	if (flag == X)
		f_color = fdf->map->coords[fdf->draw->y][fdf->draw->x + 1]->color
	== EMPTY ? fdf->cam->std_color :
	fdf->map->coords[fdf->draw->y][fdf->draw->x + 1]->color;
	if (flag == Y)
		f_color = fdf->map->coords[fdf->draw->y + 1][fdf->draw->x]->color
	== EMPTY ? fdf->cam->std_color :
	fdf->map->coords[fdf->draw->y + 1][fdf->draw->x]->color;
	fdf->draw->precent = get_precent(fdf, p, d);
	return (fill_grad(fdf, s_color, f_color));
}

static void		set_point_to_addr(t_fdf *fdf, int e_x, int e_y, int color)
{
	int ct;

	if (e_x >= 0 && e_x < WIDTH && e_y >= 0 && e_y < HEIGHT)
	{
		ct = (e_x * (fdf->bts_pr_pxl / 8)) + (e_y * fdf->sz_ln);
		fdf->data_addr[ct] = color;
		fdf->data_addr[++ct] = color >> 8;
		fdf->data_addr[++ct] = color >> 16;
		fdf->data_addr[++ct] = fdf->cam->alpha;
	}
}

static void		bresenham_algo(t_fdf *fdf, t_e_point s, t_e_point f, char flag)
{
	t_e_point	d;
	t_e_point	sgn;
	int			err[2];
	t_e_point	p;

	d.x = ft_abs(f.x - s.x);
	d.y = ft_abs(f.y - s.y);
	sgn.x = 0 < (f.x - s.x) ? 1 : -1;
	sgn.y = 0 < (f.y - s.y) ? 1 : -1;
	err[0] = d.x - d.y;
	p = s;
	while (p.x != f.x || p.y != f.y)
	{
		set_point_to_addr(fdf, p.x, p.y, get_color(fdf, p, d, flag));
		if ((err[1] = 2 * err[0]) > -d.y)
		{
			p.x += sgn.x;
			err[0] -= d.y;
		}
		if (err[1] < d.x)
		{
			p.y += sgn.y;
			err[0] += d.x;
		}
	}
}

static void		ft_draw_map(t_fdf *fdf)
{
	if (fdf->draw->x + 1 < fdf->map->width)
	{
		converter(fdf, &fdf->draw->strt, fdf->draw->x, fdf->draw->y);
		converter(fdf, &fdf->draw->fnsh, fdf->draw->x + 1, fdf->draw->y);
		if ((fdf->draw->strt.x < WIDTH + WIDTH / 2 && fdf->draw->strt.y >= 0) ||
			(fdf->draw->fnsh.x < WIDTH + WIDTH / 2 && fdf->draw->fnsh.y >= 0))
			bresenham_algo(fdf, fdf->draw->strt, fdf->draw->fnsh, X);
	}
	if (fdf->draw->y + 1 < fdf->map->height)
	{
		converter(fdf, &fdf->draw->strt, fdf->draw->x, fdf->draw->y);
		converter(fdf, &fdf->draw->fnsh, fdf->draw->x, fdf->draw->y + 1);
		if ((fdf->draw->strt.x < WIDTH + WIDTH / 2 && fdf->draw->strt.y >= 0) ||
			(fdf->draw->fnsh.x < WIDTH + WIDTH / 2 && fdf->draw->fnsh.y >= 0))
			bresenham_algo(fdf, fdf->draw->strt, fdf->draw->fnsh, Y);
	}
}

void			ft_draw(t_fdf *fdf)
{
	ft_bzero(fdf->data_addr, (WIDTH * fdf->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->draw->y = -1;
	while (++fdf->draw->y < fdf->map->height)
	{
		fdf->draw->x = -1;
		while (++fdf->draw->x < fdf->map->width)
			ft_draw_map(fdf);
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	draw_menu(fdf);
}
