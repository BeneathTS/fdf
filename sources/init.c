#include "fdf.h"

void ft_init(t_fdf *fdf)
{
	fdf->cam.zoom = 20;
	fdf->cam.prj = ISO;
	fdf->cam.x_offset = WIDTH / 4;
	fdf->cam.y_offset = HEIGHT / 4;
	fdf->cam.z_offset = 5;
	fdf->map.point = NULL;
	fdf->map.width = 0;
	fdf->map.height = 0;
	// fdf->cam.angle_x = 0;
	// fdf->cam.angle_y = 0;
	// fdf->cam.angle_z = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bts_pr_pxl, &fdf->sz_ln, &fdf->endian);
}
