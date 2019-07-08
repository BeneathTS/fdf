#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_init(&fdf);
	ft_reader(argc, argv, &fdf);
	ft_draw(&fdf);
	init_key_hooks(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
