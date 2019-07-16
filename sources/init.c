#include "fdf.h"

static t_camera *cam_init()
{
	t_camera *cam;

	cam = (t_camera*)malloc(sizeof(t_camera));
	cam->alpha = 0;
	cam->angle_x = 0;
	cam->angle_y = 0;
	cam->angle_z = 0;
	cam->algo_type = BRSH;
	cam->std_color = WHITE;
	cam->prj = ISO;
	cam->zoom = 20;
	cam->x_offset = WIDTH / 2;
	cam->y_offset = HEIGHT / 2;
	cam->z_offset = 5;
	return (cam);
}

static t_map *map_init()
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	return (map);
}

static t_draw *draw_init()
{
	t_draw *draw;

	draw = (t_draw*)malloc(sizeof(t_draw));
	return (draw);
}

void fdf_init(t_fdf *fdf)
{
	fdf->map = map_init();
	fdf->cam = cam_init();
	fdf->draw = draw_init();
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bts_pr_pxl, &fdf->sz_ln, &fdf->endian);
}
