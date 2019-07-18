NAME = fdf

SRCS =	sources/fdf.c \
		sources/read_map.c \
		sources/ft_draw.c \
		sources/init.c \
		sources/hooks.c \
		sources/key_controls.c \
		sources/color.c \
		sources/get_coordinates.c \
		sources/converter.c \


L_LIB = libft/libft.a

I_LIB = -I libft/includes

L_MLX = -L /usr/local/lib

I_MLX = -I /usr/local/include

I_FDF = -I sources/includes/

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): lib $(SRCS)
	gcc $(CFLAGS) $(SRCS) $(L_LIB) $(L_MLX) $(I_FDF) $(I_LIB) $(I_MLX) $(MLXFLAGS) -o $(NAME)

lib:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
