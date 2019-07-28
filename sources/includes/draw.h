#ifndef DRAW_H
# define DRAW_H

# define ISO 1
# define PARAL 0

# define WU 1
# define BRSH 2

# define OPEN 1
# define CLOSED 0

# define WHITE 0xFFFFFF
# define D_WHITE 0x525252
# define HDR_CLR 0xBB91FF

# define R 0
# define G 1
# define B 2

# define X 0
# define Y 1

# define EMPTY 0

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
	t_point			***coords;
}					t_map;

typedef struct		s_draw
{
	int				x;
	int				y;
	t_e_point		strt;
	t_e_point		fnsh;
}					t_draw;

typedef struct		s_camera
{
	int				alpha;
	float			angle_x;
	float			angle_y;
	float			angle_z;
	int				std_color;
	char			prj;
	long long int	zoom;
	long long int	x_offset;
	long long int 	y_offset;
	float			z_offset;
	char			menu;
}					t_camera;


#endif
