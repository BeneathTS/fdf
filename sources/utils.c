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
		else if (ct > 7 && line[ct])
			return (WHITE);
	return (num);
}
