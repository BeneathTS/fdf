#include "fdf.h"

static t_camera *cam_init()
{
	t_camera *cam;

	if (!(cam = (t_camera*)malloc(sizeof(t_camera))))
		return (NULL);
	cam->alpha = 0;
	cam->angle_x = 0;
	cam->angle_y = 0;
	cam->angle_z = 0;
	cam->std_color = WHITE;
	cam->prj = ISO;
	cam->zoom = 20;
	cam->x_offset = WIDTH / 2;
	cam->y_offset = HEIGHT / 2;
	cam->z_offset = 1;
	cam->menu = CLOSED;
	return (cam);
}

static t_map *map_init()
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->coords = NULL;
	return (map);
}

static t_draw *draw_init()
{
	t_draw *draw;

	if (!(draw = (t_draw*)malloc(sizeof(t_draw))))
		return (NULL);
	return (draw);
}

static t_cntrls *cntrls_init()
{
	t_cntrls *cntrls;

	if (!(cntrls = (t_cntrls*)malloc(sizeof(t_cntrls))))
		return (NULL);
	cntrls->rght_prssd = NO;
	cntrls->lft_prssd = NO;
	cntrls->RGB = R;
	return (cntrls);
}

void fdf_init(t_fdf *fdf)
{
	if (!(fdf->map = map_init()))
		terminate(NO_MEMRY_ERROR, fdf);
	if (!(fdf->cam = cam_init()))
		terminate(NO_MEMRY_ERROR, fdf);
	if (!(fdf->draw = draw_init()))
		terminate(NO_MEMRY_ERROR, fdf);
	if (!(fdf->cntrls = cntrls_init()))
		terminate(NO_MEMRY_ERROR, fdf);
	if (!(fdf->mlx = mlx_init()))
		terminate(NO_MEMRY_ERROR, fdf);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf")))
		terminate(NO_MEMRY_ERROR, fdf);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		terminate(NO_MEMRY_ERROR, fdf);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bts_pr_pxl, &fdf->sz_ln, &fdf->endian);
}
