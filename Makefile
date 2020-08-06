# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseabass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 22:43:19 by cseabass          #+#    #+#              #
#    Updated: 2020/08/06 22:43:20 by cseabass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/main.c src/key.c src/check_args.c src/color.c src/mouse.c
FLAG = -Wall -Wextra -Werror
LIB = libft/libft.a
NAME = fractol
MLX_FLAGS = -L ./MinilibX -lm -lmlx -framework OpenGL -framework AppKit
OBJ = $(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft re
	@make -C ./MinilibX
	@gcc $(FLAG) -L libft -lft $(FILES) -I includes/libft -I src/fractal.h -o $(NAME) $(MLX_FLAGS)
%.o: %.c
	@gcc -I src/fractal.h -I ./MinilibX -I ./libft $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@rm -rf ./MinilibX/*.o

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@rm -rf ./MinilibX/libmlx.a

re: fclean all

.PHONY: all clean fclean re
