#include "fdf.h"

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
