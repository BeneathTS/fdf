/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:26:32 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 19:26:33 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		x_close(t_fdf *fdf)
{
	terminate(EXIT, fdf);
	return (0);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KB_NUM_5)
		fdf->cam->angle_x += 0.05;
	if (key == KB_NUM_8)
		fdf->cam->angle_x -= 0.05;
	if (key == KB_NUM_4)
		fdf->cam->angle_y += 0.05;
	if (key == KB_NUM_6)
		fdf->cam->angle_y -= 0.05;
	if (key == KB_NUM_9)
		fdf->cam->angle_z += 0.05;
	if (key == KB_NUM_7)
		fdf->cam->angle_z -= 0.05;
	ft_draw(fdf);
}

void	set_alpha(int key, t_fdf *fdf)
{
	if (key == KB_NUM_STR && fdf->cam->alpha)
		fdf->cam->alpha -= 5;
	if (key == KB_NUM_SLSH && fdf->cam->alpha != 0xFF)
		fdf->cam->alpha += 5;
	ft_draw(fdf);
}
