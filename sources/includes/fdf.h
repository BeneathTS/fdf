#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
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

# define WU 1
# define BRSH 2

# define WHITE 0xFFFFFF

# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_point
{
	int				z;
	int				color;
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
	t_point			**coords;
}					t_map;

typedef struct		s_draw
{
	int				x;
	int				y;
	t_e_point		*strt;
	t_e_point		*fnsh;
}					t_draw;

typedef struct		s_camera
{
	int				alpha;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	int				algo_type;
	int				std_color;
	char			prj;
	long long int	zoom;
	long long int	x_offset;
	long long int 	y_offset;
	long long int	z_offset;
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
	t_map			*map;
	t_draw			*draw;
	t_camera		*cam;
}					t_fdf;

void				read_map(int argc, char **argv, t_fdf *fdf);
t_point				*new_coordinate();
void				ft_free_matrix(t_map **map);
int					key_controls(int key, t_fdf *fdf);
void				fdf_init(t_fdf *fdf);
void				ft_draw(t_fdf *fdf);
void				init_key_hooks(t_fdf *fdf);
int					move(int key, t_fdf *fdf);
int					zoom(int key, t_fdf *fdf);
int					change_projection(int key, t_fdf *fdf);
int					read_color(char *line);
int					change_z(int key, t_fdf *fdf);
t_e_point			*converter(t_fdf *fdf, int x, int y);
void				get_coordinates(char **argv, t_fdf *fdf);
void				get_values(char *line, t_fdf *fdf, int x, int y);
#endif
