/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:26:36 by ahiroko           #+#    #+#             */
/*   Updated: 2019/07/28 19:26:37 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			menu(t_fdf *fdf)
{
	fdf->cam->menu = (fdf->cam->menu == CLOSED ? OPEN : CLOSED);
	fdf->cam->alpha = (fdf->cam->menu == OPEN ? 0xDF : 0);
	ft_draw(fdf);
}

static void		draw_headers(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 21,
	HEIGHT / 2 - 200, HDR_CLR, "MOVE:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 21,
	HEIGHT / 2 - 140, HDR_CLR, "ZOOM:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 29,
	HEIGHT / 2 - 80, HDR_CLR, "ROTATE:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 25,
	HEIGHT / 2 - 20, HDR_CLR, "ALPHA:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 50,
	HEIGHT / 2 + 40, HDR_CLR, "Z-ACCURACY:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 25,
	HEIGHT / 2 + 100, HDR_CLR, "COLOR:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 50,
	HEIGHT / 2 + 160, HDR_CLR, "PROJECTION:");
}

static void		draw_info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 220,
	HEIGHT / 2 - 175, WHITE, "Mouse (left-click + move) / Keyboard (arrows)");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 145,
	HEIGHT / 2 - 115, WHITE, "Mouse (scroll) / Keyboard (+/-)");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 291, HEIGHT / 2 - 55, WHITE,
	"Mouse (right-click + move) / Keyboard (num: 9, 8, 7, 6, 5, 4)");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 90,
	HEIGHT / 2 + 5, WHITE, "Keyboard (num: /, *)");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 70,
	HEIGHT / 2 + 65, WHITE, "Keyboard ([ / ])");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 55,
	HEIGHT / 2 + 125, WHITE, "Keyboard (C)");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 130,
	HEIGHT / 2 + 185, WHITE, "Keyboard (ISO: i / PARAL: p)");
}

void			draw_menu(t_fdf *fdf)
{
	if (fdf->cam->menu == CLOSED)
		mlx_string_put(fdf->mlx, fdf->win, 15, 15, WHITE, "help - f1");
	else
	{
		mlx_string_put(fdf->mlx, fdf->win, 15, 15, D_WHITE, "close - f1");
		draw_headers(fdf);
		draw_info(fdf);
	}
}
