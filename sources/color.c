/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:26:03 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 21:23:05 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_color(char *line)
{
	int ct;
	int num;

	if (line[0] != '0' && line[1] != 'x')
		return (ERROR);
	ct = 1;
	num = 0x0;
	while (line[++ct])
		if ((line[ct] >= '0' && line[ct] <= '9') && ct < 8)
			num |= ((0x0 + (line[ct] - '0')) & ~num) << (4 * (7 - ct));
		else if ((line[ct] >= 'A' && line[ct] <= 'F') && ct < 8)
			num |= ((0xA + (line[ct] - 'A')) & ~num) << (4 * (7 - ct));
		else if ((line[ct] >= 'a' && line[ct] <= 'f') && ct < 8)
			num |= ((0xA + (line[ct] - 'a')) & ~num) << (4 * (7 - ct));
		else if (ct > 7 && line[ct])
			return (EMPTY);
	return (num);
}

int		get_values(char *line, t_fdf *fdf, int x, int y)
{
	char	**splitted;
	int		ct;

	if (!(splitted = ft_strsplit(line, ',')))
		return (ERROR);
	fdf->map->coords[y][x] = new_coordinate(fdf);
	fdf->map->coords[y][x]->z = ft_atoi(splitted[0]);
	free(splitted[0]);
	if (splitted[1])
	{
		if ((fdf->map->coords[y][x]->color = read_color(splitted[1]))
		== ERROR || splitted[2])
		{
			ct = 2;
			while (splitted[ct])
				free(splitted[ct++]);
			return (ERROR);
		}
		free(splitted[1]);
	}
	else
		fdf->map->coords[y][x]->color = EMPTY;
	free(splitted);
	return (SUCCESS);
}

double	get_precent(t_fdf *fdf, t_e_point p, t_e_point d)
{
	double placement;
	double distance;
	double precentage;

	if (d.x > d.y)
	{
		placement = p.x - fdf->draw->strt.x;
		distance = fdf->draw->fnsh.x - fdf->draw->strt.x;
		precentage = (distance == 0 ? 1.0 : (placement / distance));
	}
	else
	{
		placement = p.y - fdf->draw->strt.y;
		distance = fdf->draw->fnsh.y - fdf->draw->strt.y;
		precentage = (distance == 0 ? 1.0 : (placement / distance));
	}
	return (precentage);
}

int		fill_grad(t_fdf *fdf, int s_clr, int f_clr)
{
	int r;
	int g;
	int b;

	r = (int)((1 - fdf->draw->precent) * ((s_clr >> 16) & 0xFF) +
	(fdf->draw->precent) * ((f_clr >> 16) & 0xFF));
	g = (int)((1 - fdf->draw->precent) * ((s_clr >> 8) & 0xFF) +
	(fdf->draw->precent) * ((f_clr >> 8) & 0xFF));
	b = (int)((1 - fdf->draw->precent) * (s_clr & 0xFF) +
	(fdf->draw->precent) * (f_clr & 0xFF));
	return ((r << 16) | (g << 8) | b);
}
