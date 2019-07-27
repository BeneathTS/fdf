#include "fdf.h"

static int check_file_format_n_args(int ct, char **argv, t_fdf *fdf)
{
	int fd;

	if (ct < 2)
		terminate(INPUT_ERROR, fdf, NO);
	else if (ct > 2)
		terminate(TOO_MANY_FILES, fdf, NO);
	if ((fd = open(FILE_NAME, O_RDONLY)) == ERROR)
		terminate(FILE_ERROR, fdf, NO);
	ct = 0;
	while (FILE_NAME[ct])
		++ct;
	if (FILE_NAME[ct - 1] != 'f' || FILE_NAME[ct - 2] != 'd'
	|| FILE_NAME[ct - 3] != 'f' || FILE_NAME[ct - 4] != '.')
	{
		close(fd);
		terminate(INPUT_ERROR, fdf, NO);
	}
	return (fd);
}

static int ft_convert(char *line, t_fdf *fdf)
{
	int ct;
	char **splitted;

	if (!(splitted = ft_strsplit(line, ' ')))
		return (ERROR);
	ct = -1;
	while (splitted[++ct])
		free(splitted[ct]);
	free(splitted);
	if ((ct > fdf->map->width && fdf->map->width) || ct < fdf->map->width)
		terminate(MAP_ERROR, fdf, NO);
	fdf->map->width = ct;
	return (SUCCESS);
}

static void ft_writer(int fd, t_fdf *fdf)
{
	int status;
	char *line;

	while ((status = get_next_line(fd, &line)) == READING)
	{
		++fdf->map->height;
		if ((ft_convert(line, fdf)) == ERROR)
		{
			free(line);
			close(fd);
			terminate(MAP_READ_ERROR, fdf, NO);
		}
		free(line);
	}
	free(line);
	if (status == ERROR)
		terminate(MAP_READ_ERROR, fdf, NO);
}

void read_map(int argc, char **argv, t_fdf *fdf)
{
	int fd;

	fd = check_file_format_n_args(argc, argv, fdf);
	ft_writer(fd, fdf);
	if (fdf->map->width <= 1 || fdf->map->height <= 1)
		terminate(MAP_ERROR, fdf, NO);
	close(fd);
}
