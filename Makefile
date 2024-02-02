# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: velbling <velbling@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:15:30 by velbling          #+#    #+#              #
#    Updated: 2024/01/16 16:50:42 by velbling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

FILES = main \
		get_next_line \
		get_next_line_utils \
		map

#MLX = MLX42/build/libmlx42.a -L "/Users/$$USER/.brew/opt/glfw/lib/" -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLX = MLX42/build/libmlx42.a -L "/Users/$$USER/.brew/opt/glfw/lib/" -lglfw -lm#-framework Cocoa -framework OpenGL -framework IOKit

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))

GFLAG = -Wall -Wextra -Werror #-fsanitize=address -g3

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(GFLAG) $(OBJ) -o $(NAME) $(MLX)

.c.o:
	gcc $(GFLAG) -c -o $@ $< -I includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

r: re
	./$(NAME) maps/test.cub

run:
	./$(NAME) maps/test.cub

re: fclean all