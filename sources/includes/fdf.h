#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"
# include "errors.h"
# include "controls.h"
# include "get_next_line.h"

# define ERROR -1
# define SUCCESS 1

# define READING 1

# define FILE_NAME argv[1]

# define ISO 1
# define PARAL 0

# define WHITE 0xFFFFFF

# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
	struct s_point	*prev;
}					t_point;

typedef struct		s_e_point
{
	int				x;
	int				y;
	int				z;
}					t_e_point;

typedef struct		s_map
{
	int				width;
	int				height;
	t_e_point		e_point;
	t_point			*point;
}					t_map;

typedef struct		s_camera
{
	char			prj;
	long long int	zoom;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	int				alpha;
	long long int	x_offset;
	long long int 	y_offset;
}					t_camera;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char 			*data_addr;
	int				bts_pr_pxl;
	int				sz_ln;
	int				endian;
	t_map			map;
	t_camera		cam;
}					t_fdf;

void				ft_reader(int argc, char **argv, t_fdf *fdf);
t_point				*new_point(t_point *prev);
void				ft_free_matrix(t_map **map);
int					key_controls(int key, t_fdf *fdf);
void				ft_init(t_fdf *fdf);
void				ft_draw(t_fdf *fdf);
void				init_key_hooks(t_fdf *fdf);
int					move(int key, t_fdf *fdf);
int					zoom(int key, t_fdf *fdf);
int					change_projection(int key, t_fdf *fdf);
int					read_color(char *line);
int					converter(t_fdf *fdf);
#endif
