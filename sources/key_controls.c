/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:26:26 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 19:34:17 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == KB_NUM_PLUS ||
		key == KB_STD_PLUS ||
		key == MS_SCRL_DWN)
		fdf->cam->zoom++;
	else if (key == KB_NUM_MINUS ||
		key == KB_STD_MINUS ||
		key == MS_SCRL_UP)
		fdf->cam->zoom--;
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	ft_draw(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == KB_KEY_LEFT)
		fdf->cam->x_offset -= 15;
	else if (key == KB_KEY_RIGHT)
		fdf->cam->x_offset += 15;
	else if (key == KB_KEY_UP)
		fdf->cam->y_offset -= 15;
	else if (key == KB_KEY_DOWN)
		fdf->cam->y_offset += 15;
	ft_draw(fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == KB_KEY_I)
		fdf->cam->prj = ISO;
	else if (key == KB_KEY_P)
		fdf->cam->prj = PARAL;
	fdf->cam->angle_x = 0;
	fdf->cam->angle_y = 0;
	fdf->cam->angle_z = 0;
	ft_draw(fdf);
}

void	change_z(int key, t_fdf *fdf)
{
	if (key == KB_KEY_Z_PLS)
		fdf->cam->z_offset += 0.3;
	else if (key == KB_KEY_Z_MNS)
		fdf->cam->z_offset -= 0.15;
	if (fdf->cam->z_offset >= 20)
		fdf->cam->z_offset = 20;
	if (fdf->cam->z_offset <= 0)
		fdf->cam->z_offset = 0.1;
	ft_draw(fdf);
}

void	change_color(t_fdf *fdf)
{
	if (fdf->cntrls->rgb == R && (fdf->cam->std_color >> 8) != 0xFF)
		fdf->cam->std_color += ((fdf->cam->std_color & (0xFF << 8)) <
		(0xFF << 8) ? 0x000500 : -0x050000);
	else if (fdf->cntrls->rgb == R && (fdf->cam->std_color >> 8) == 0xFF)
		fdf->cntrls->rgb = G;
	if (fdf->cntrls->rgb == G && fdf->cam->std_color != 0xFF)
		fdf->cam->std_color += ((fdf->cam->std_color & 0xFF) <
		0xFF ? 0x000005 : -0x000500);
	else if (fdf->cntrls->rgb == G && fdf->cam->std_color == 0xFF)
		fdf->cntrls->rgb = B;
	if (fdf->cntrls->rgb == B && fdf->cam->std_color != (0xFF << 16))
		fdf->cam->std_color += ((fdf->cam->std_color & (0xFF << 16)) <
		(0xFF << 16) ? 0x050000 : -0x000005);
	else if (fdf->cntrls->rgb == B && fdf->cam->std_color == (0xFF << 16))
		fdf->cntrls->rgb = R;
	ft_draw(fdf);
}
