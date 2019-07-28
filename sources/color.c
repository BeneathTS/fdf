/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:26:03 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 19:26:04 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_color(char *line)
{
	int ct;
	int num;

	if (line[0] != '0' && line[1] != 'x')
		return (EMPTY);
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

int	get_values(char *line, t_fdf *fdf, int x, int y)
{
	char **splitted;

	if (!(splitted = ft_strsplit(line, ',')))
		return (ERROR);
	fdf->map->coords[y][x] = new_coordinate(fdf);
	fdf->map->coords[y][x]->z = ft_atoi(splitted[0]);
	free(splitted[0]);
	if (splitted[1])
	{
		fdf->map->coords[y][x]->color = read_color(splitted[1]);
		free(splitted[1]);
		if (splitted[2])
		{
			free(splitted[2]);
			free(splitted);
			return (ERROR);
		}
	}
	else
		fdf->map->coords[y][x]->color = EMPTY;
	free(splitted);
	return (SUCCESS);
}

// int fill_grad(int s_clr, int f_clr, int s_x int f_x, int ct)
// {
// 	int r;
// 	int g;
// 	int b;
//
// 	// x = (ct - s_x)/(f_x - s_x)
//
// 	r = (ct - s_x)/(f_x - s_x) * (s_clr & (0xFF >> 16) + (ct - s_x)/(f_x - s_x) * (f_clr & (0xFF >> 16));
// 	g = (ct - s_x)/(f_x - s_x) * (s_clr & (0xFF >> 8)) + (ct - s_x)/(f_x - s_x) * (f_clr & (0xFF >> 8));
// 	b = (ct - s_x)/(f_x - s_x) * (s_clr & 0xFF) + (ct - s_x)/(f_x - s_x) * (f_clr & 0xFF);
// 	return ((r << 16) | (g << 8) | b);
// }
