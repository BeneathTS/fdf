#include "fdf.h"

int read_color(char *line)
{
	int ct;
	int num;

	if (line[0] != '0' && line[1] != 'x')
		return (WHITE);
	ct = 1;
	num = 0x0;
	while (line[++ct])
		if ((line[ct] >= '0' && line[ct] <= '9') && ct < 8)
			num |= ((0x0 + (line[ct] - '0')) & ~num) << (4 * (7 - ct));
		else if ((line[ct] >= 'A' && line[ct] <= 'F') && ct < 8)
			num |= ((0xA + (line[ct] - 'A')) & ~num) << (4 * (7 - ct));
		else if ((line[ct] >= 'a' && line[ct] <= 'f') && ct < 8)
			num |= ((0xA + (line[ct] - 'a')) & ~num) << (4 * (7 - ct));
		else if (ct > 7 && line[ct])
			return (WHITE);
	return (num);
}

void get_values(char *line, t_fdf *fdf, int x, int y)
{
	char **splitted;

	splitted = ft_strsplit(line, ',');

	fdf->map->coords[y][x] = *new_coordinate(fdf);
	fdf->map->coords[y][x].z = ft_atoi(splitted[0]);
	free(splitted[0]);
	if(splitted[1])
	{
		fdf->map->coords[y][x].color = read_color(splitted[1]);
		free(splitted[1]);
	}
	else
		fdf->map->coords[y][x].color = WHITE;
	free(splitted);
}
