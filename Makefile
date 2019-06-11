NAME = fdf

SRCS = fdf.c

I_LIB = -I libft/includes

L_MLX = -L /usr/local/lib

I_MLX = -I /usr/local/include

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): lib $(SRCS)
	gcc $(CFLAGS) $(SRCS) $(L_MLX) $(I_LIB) $(I_MLX) $(MLXFLAGS) -o $(NAME)

lib:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
