# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 18:43:02 by ayagoumi          #+#    #+#              #
#    Updated: 2019/11/18 06:28:07 by ayagoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

lib = ./libft/libft.a

SRCS = ./srcs/bresenham.c ./srcs/check_file.c ./srcs/checker.c \
		./srcs/ft_even.c ./srcs/hook.c ./srcs/hook_events.c ./srcs/main.c \
		./srcs/moves.c ./srcs/other_bresenham.c ./srcs/projections.c \
		./srcs/put_to_window.c ./srcs/zoom.c ./srcs/other_hooks.c \
		./srcs/duplicate.c 

CC = gcc

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

FRAM = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2;36m"
	@make -C libft 2> /dev/null || true
	mkdir -p ./obj
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(FRAM) $(lib) 2> /dev/null || true
	@mv ./srcs/*.o ./obj
	@echo "fdf: executable file is ready"
	@echo "\033[0m"

clean:
	@echo "\033[2;32m"
	@rm -rf $(OBJ) 2> /dev/null || true
	@make -C libft clean 2> /dev/null || true
	@rm -rf ./obj
	@echo "fdf: all resources deleted"
	@echo "\033[0m"

fclean: clean
	@echo "\033[2;34m"
	@rm -rf $(NAME) 2> /dev/null || true
	@make -C libft fclean 2> /dev/null || true
	@echo "fdf: all resources deleted"
	@echo "\033[0m"

re: fclean all
