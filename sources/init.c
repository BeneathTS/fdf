#include "fdf.h"

void ft_init(t_fdf *fdf)
{
	fdf->cam.zoom = 20;
	fdf->cam.prj = ISO;
	fdf->cam.x_offset = WIDTH / 2;
	fdf->cam.y_offset = HEIGHT / 2;
	//fdf->map.point = NULL;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, fdf->wndw_nm);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bts_pr_pxl, &fdf->sz_ln, &fdf->endian);
}
