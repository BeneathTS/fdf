#include "fdf.h"

t_point	*new_coordinate(t_fdf *fdf)
{
	t_point *new;

	if (!(new = (t_point*)malloc(sizeof(t_point))))
		terminate(NO_MEMRY_ERROR, fdf, fdf->map->height);
	return (new);
}

static void new_map(t_fdf *fdf, int fd)
{
	int ct;

	ct = -1;
	if (!(fdf->map->coords = (t_point**)malloc(sizeof(t_point*) * (fdf->map->height + 1))))
	{
		close(fd);
		terminate(NO_MEMRY_ERROR, fdf, NO);
	}
	while (++ct < fdf->map->height)
	{
		if (!(fdf->map->coords[ct] = (t_point*)malloc(sizeof(t_point) * (fdf->map->width + 1))))
		{
			close(fd);
			terminate(NO_MEMRY_ERROR, fdf, ct);
		}
		ft_bzero(fdf->map->coords[ct], fdf->map->width + 1);
	}
	fdf->map->coords[ct] = NULL;
}

static int ft_convert(char *line, t_fdf *fdf, int y)
{
	int ct;
	char **splitted;
	int status;

	if (!(splitted = ft_strsplit(line, ' ')))
		return (ERROR);
	ct = -1;
	status = 0;
	while (splitted[++ct])
	{
		if (get_values(splitted[ct], fdf, ct, y) == ERROR)
			status = ERROR;
		free(splitted[ct]);
	}
	free(splitted);
	return (status == ERROR ? ERROR : SUCCESS);
}

static void read_coordinates(t_fdf *fdf, int fd)
{
	int ct;
	char *line;
	int y;

	y = 0;
	while ((ct = get_next_line(fd, &line)) == READING)
	{
		if ((ft_convert(line, fdf, y++)) == ERROR)
		{
			free(line);
			close(fd);
			terminate(MAP_READ_ERROR, fdf, fdf->map->height);
		}
		free(line);
	}
	free(line);
}

void	get_coordinates(char **argv, t_fdf *fdf)
{
	int fd;

	if ((fd = open(FILE_NAME, O_RDONLY)) == ERROR)
		terminate(FILE_ERROR, fdf, NO);
	new_map(fdf, fd);
	read_coordinates(fdf, fd);
}
