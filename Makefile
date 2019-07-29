NAME = fdf

SRCS =	fdf.c \
		read_map.c \
		ft_draw.c \
		init.c \
		hooks.c \
		key_controls.c \
		color.c \
		get_coordinates.c \
		converter.c \
		mouse_controls.c \
		key_controls2.c \
		menu.c \

OS = $(SRCS:.c=.o)

SRCDIR = sources

L_LIB = libft/libft.a

I_LIB = -I libft/includes

L_MLX = -L /usr/local/lib

I_MLX = -I /usr/local/include

I_FDF = -I sources/includes

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

vpath %.c $(SRCDIR)

.PHONY: all lib clean fclean re norm

all: lib $(NAME)

$(NAME): $(OS)
	@gcc $(CFLAGS) $^ $(L_LIB) $(L_MLX) $(I_FDF) $(I_LIB) $(I_MLX) $(MLXFLAGS) -o $(NAME)

$(OS): $(SRCS)
	@gcc $(CFLAGS) -c $^ $(I_FDF) $(I_LIB) $(I_MLX)

lib:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OS)

re: fclean all
