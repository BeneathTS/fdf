#include "fdf.h"

static void free_mem(t_fdf *fdf)
{
	free((void*)fdf->cam);
	free((void*)fdf->map);
	free((void*)fdf->draw);
	free((void*)fdf->cntrls);
	ft_bzero(fdf->data_addr, (WIDTH * fdf->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->data_addr = NULL;
	mlx_destroy_window(fdf->mlx, fdf->win);
}

void terminate(int flag, t_fdf *fdf)
{
	if (flag == NO_MEMRY_ERROR)
		errno = ENOMEM;
	else if (flag == TOO_MANY_FILES)
		errno = E2BIG;
	else if (flag == MAP_READ_ERROR)
		ft_putstr("\033[1;31mError\033[0m: Map reading error!\n");
	else if (flag == MAP_ERROR)
		ft_putstr("\033[1;31mError\033[0m: Invalid Map!\n");
	else if (flag == INPUT_ERROR)
		ft_putstr("\033[1;33mUsage\033[0m: fdf filename.fdf\n");
	else if (flag == FILE_ERROR)
		errno = ENOENT;
	if (flag == NO_MEMRY_ERROR || flag == TOO_MANY_FILES || flag == FILE_ERROR)
		perror("\033[1;31mError\033[0m");
	free_mem(fdf);
	exit(flag);
}

int main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf_init(&fdf);
	read_map(argc, argv, &fdf);
	get_coordinates(argv, &fdf);
	ft_draw(&fdf);
	init_key_hooks(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
