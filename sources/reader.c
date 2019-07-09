#include "fdf.h"

static void check_file_format_n_args(int ct, char **argv)
{
	if (ct != 2)
	{
		ft_putstr("\033[1;33musage\033[0m: fdf filename.fdf\n");
		exit(ERROR);
	}
	ct = 0;
	while (FILE_NAME[ct])
		++ct;
	if (FILE_NAME[ct - 1] != 'f' || FILE_NAME[ct - 2] != 'd'
	|| FILE_NAME[ct - 3] != 'f' || FILE_NAME[ct - 4] != '.')
	{
		ft_putstr("\033[1;33musage\033[0m: fdf filename.fdf\n");
		exit(ERROR);
	}
}

static void get_values(char *line, t_fdf *fdf)
{
	char **splitted;

	splitted = ft_strsplit(line, ',');
	if (!fdf->map.point)
		fdf->map.point = new_point(fdf->map.point);
	else
	{
		fdf->map.point->next = new_point(fdf->map.point);
		fdf->map.point = fdf->map.point->next;
	}
	fdf->map.point->z = ft_atoi(splitted[0]);
	free(splitted[0]);
	if(splitted[1])
	{
		fdf->map.point->color = read_color(splitted[1]);
		free(splitted[1]);
	}
	else
		fdf->map.point->color = WHITE;
	free(splitted);
}

static void ft_convert(char *line, t_fdf *fdf)
{
	int ct;
	char **splitted;

	splitted = ft_strsplit(line, ' ');
	ct = -1;
	while (splitted[++ct])
	{
		fdf->map.width = ct;
		get_values(splitted[ct], fdf);
		free(splitted[ct]);
	}
	free(splitted);
}

static void ft_writer(int fd, t_fdf *fdf)
{
	int status;
	char *line;

	while ((status = get_next_line(fd, &line)) == READING)
	{
		fdf->map.height++;
		ft_convert (line, fdf);
		free(line);
	}
	free(line);
}

void ft_reader(int argc, char **argv, t_fdf *fdf)
{
	int fd;

	check_file_format_n_args(argc, argv);
	if ((fd = open(FILE_NAME, O_RDONLY)) == ERROR)
	{
		perror("\033[1;31mError\033[0m");
		exit(ERROR);
	}
	ft_writer(fd, fdf);
}
