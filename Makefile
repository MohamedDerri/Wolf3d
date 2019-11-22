# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 23:51:03 by mderri            #+#    #+#              #
#    Updated: 2019/11/22 22:00:34 by slaanani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS1 = -Wextra -Wall -Werror -I ./libs/mlx -I ./includes -I ./libs/libft
CFLAGS2 = -L ./libs/libft -lft -I ./includes -I ./libs/libft -I ./libs/mlx -L ./libs/mlx -lmlx -framework OpenGL -framework AppKit
NAME = wolf3d

SRC =	keyhandle.c\
		tools.c\
		transformations.c\
		vector_operations.c\
		vector_operations2.c\
		raycaster.c\
		wolf3d.c

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:%.c=objs/%.o)
DIRECTORY = objs

all: $(NAME)

$(NAME): $(DIRECTORY) $(OBJ)
	@echo "\033[0;31m============ MAKING WOLF3D ...\033[0m"
	@echo "\033[0;31m=============== MAKING LIBFT ...\033[0m"
	@make -C ./libs/libft
	@echo "\033[0;32m=============== SUCESS ...\033[0m"
	@echo "\033[0;31m=============== MAKING MINILIBX ...\033[0m"
	@make -C ./libs/mlx
	@echo "\033[0;32m=============== SUCESS ...\033[0m"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS1) $(CFLAGS2)
	@echo "\033[0;32m============ SUCESS ...\033[0m"
	@echo "\033[0;32mYOUR WOLF3D HAS BEEN COMPILED SUCCESSFULLY\033[0m"

$(DIRECTORY):
	@mkdir -p objs

objs/%.o: srcs/%.c
	@gcc $(CFLAGS1) -c $< -o $@

clean:
	@echo "\033[0;31m=============== CLEANING THE MESS ...\033[0m"
	@rm -rf objs
	@rm -f $(OBJ)
	@make clean -C ./libs/libft
	@make clean -C ./libs/mlx
	@echo "\033[0;32m=============== SUCESS\033[0m"

fclean: clean
	@echo "\033[0;31m=============== CLEANING THE MESS FOR REAL...\033[0m"
	@make fclean -C ./libs/libft
	@make clean -C ./libs/mlx
	@rm -f $(NAME)
	@echo "\033[0;32m=============== SUCESS\033[0m"

re: fclean all
.PHONY: fclean, clean, re, all, rtv1
