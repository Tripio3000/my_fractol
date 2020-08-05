# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vabraham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 18:54:24 by vabraham          #+#    #+#              #
#    Updated: 2019/11/13 16:56:07 by vabraham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/main.c src/key.c
FLAG = -Wall -Wextra -Werror
LIB = libft/libft.a
NAME = fractol
MLX_FLAGS = -L ./MinilibX -lm -lmlx -framework OpenGL -framework AppKit
OBJ = $(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft re
	@make -C ./MinilibX
	@gcc -L libft -lft $(FILES) -I includes/libft -I src/fractal.h -o $(NAME) $(MLX_FLAGS)
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
