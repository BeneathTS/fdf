#include "fdf.h"

t_point	*new_coordinate()
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->z = 0;
	new->color = WHITE;
	return (new);
}

static void new_map(t_fdf *fdf)
{
	int ct;

	ct = -1;
	fdf->map->coords = (t_point**)malloc(sizeof(t_point*) * (fdf->map->height + 1));
	while (++ct < fdf->map->height)
		fdf->map->coords[ct] = (t_point*)malloc(sizeof(t_point) * (fdf->map->width + 1));
	fdf->map->coords[ct] = NULL;
}

static void ft_convert(char *line, t_fdf *fdf, int y)
{
	int ct;
	char **splitted;

	splitted = ft_strsplit(line, ' ');
	ct = -1;
	while (splitted[++ct])
	{
		get_values(splitted[ct], fdf, ct, y);
		free(splitted[ct]);
	}
	free(splitted);
}

static void read_coordinates(t_fdf *fdf, int fd)
{
	int ct;
	char *line;
	int y;

	y = 0;
	while ((ct = get_next_line(fd, &line)) == READING)
	{
		ft_convert(line, fdf, y++);
		free(line);
	}
	free(line);
}

void	get_coordinates(char **argv, t_fdf *fdf)
{
	int fd;

	if ((fd = open(FILE_NAME, O_RDONLY)) == ERROR)
	{
		perror("\033[1;31mError\033[0m");
		exit(ERROR);
	}
	new_map(fdf);
	read_coordinates(fdf, fd);
}
