/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:26:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 19:26:13 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	x_rotate(t_fdf *fdf, int *y, int *z)
{
	int buf_y;

	buf_y = *y;
	*y = buf_y * cos(fdf->cam->angle_x) + *z * sin(fdf->cam->angle_x);
	*z = -buf_y * sin(fdf->cam->angle_x) + *z * cos(fdf->cam->angle_x);
}

void	y_rotate(t_fdf *fdf, int *x, int *z)
{
	int buf_x;

	buf_x = *x;
	*x = buf_x * cos(fdf->cam->angle_y) + *z * sin(fdf->cam->angle_y);
	*z = -buf_x * sin(fdf->cam->angle_y) + *z * cos(fdf->cam->angle_y);
}

void	z_rotate(t_fdf *fdf, int *x, int *y)
{
	int buf_x;
	int buf_y;

	buf_x = *x;
	buf_y = *y;
	*x = buf_x * cos(fdf->cam->angle_z) - buf_y * sin(fdf->cam->angle_z);
	*y = buf_x * sin(fdf->cam->angle_z) + buf_y * cos(fdf->cam->angle_z);
}

void	converter(t_fdf *fdf, t_e_point *e_point, int x, int y)
{
	e_point->x = (x - fdf->map->width / 2) * fdf->cam->zoom;
	e_point->y = (y - fdf->map->height / 2) * fdf->cam->zoom;
	e_point->z = fdf->map->coords[y][x]->z * fdf->cam->zoom /
	fdf->cam->z_offset;
	x_rotate(fdf, &e_point->y, &e_point->z);
	y_rotate(fdf, &e_point->x, &e_point->z);
	z_rotate(fdf, &e_point->x, &e_point->y);
	if (fdf->cam->prj == ISO)
		iso(&e_point->x, &e_point->y, e_point->z);
	e_point->x += fdf->cam->x_offset;
	e_point->y += fdf->cam->y_offset;
}
