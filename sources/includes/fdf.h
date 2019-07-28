#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>

# include "draw.h"
# include "libft.h"
# include "controls.h"
# include "get_next_line.h"

# define ERROR -1
# define SUCCESS 1

# define READING 1

# define FILE_NAME argv[1]

# define WIDTH 1920
# define HEIGHT 1080

# define EXIT 0
# define NO_MEMRY_ERROR 1
# define MAP_READ_ERROR 2
# define TOO_MANY_FILES 3
# define FILE_ERROR 4
# define INPUT_ERROR 5
# define MAP_ERROR 6

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
	t_cntrls		*cntrls;
}					t_fdf;

void				read_map(int argc, char **argv, t_fdf *fdf);
t_point				*new_coordinate(t_fdf *fdf);
int					key_controls(int key, t_fdf *fdf);
void				fdf_init(t_fdf *fdf);
void				ft_draw(t_fdf *fdf);
void				init_key_hooks(t_fdf *fdf);
int					read_color(char *line);
void				converter(t_fdf *fdf, t_e_point *e_point, int x, int y);
void				get_coordinates(char **argv, t_fdf *fdf);
int					get_values(char *line, t_fdf *fdf, int x, int y);
void				terminate(int flag, t_fdf *fdf);

void				key_press(int button, int x, int y, t_fdf *fdf, char flag);
void				change_color(t_fdf *fdf);
void				change_projection(int key, t_fdf *fdf);
void				change_z(int key, t_fdf *fdf);
void				mouse_move(int x, int y, t_fdf *fdf);
void				move(int key, t_fdf *fdf);
void				zoom(int key, t_fdf *fdf);
void				rotate(int key, t_fdf *fdf);
void				mouse_rotate(int x, int y, t_fdf *fdf);
void				set_alpha(int key, t_fdf *fdf);
void				menu(t_fdf *fdf);
void				draw_menu(t_fdf *fdf);
// int fill_grad(int s_clr, int f_clr, int s_x, int f_x, int ct);
#endif
