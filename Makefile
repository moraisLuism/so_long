# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 09:35:15 by lmorais-          #+#    #+#              #
#    Updated: 2023/12/01 09:35:49 by lmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
INCLUDE = -I./includes
RM = rm -rf
VPATH = srcs

SRCS = ft_analyze_input.c\
	ft_count_specific_c.c\
	ft_count_lines.c\
	ft_exit.c\
	ft_exit_error.c\
	ft_init_data.c\
	ft_init_map.c\
	ft_key_event_handler.c\
	ft_line_length.c\
	ft_move.c\
	ft_put_background.c\
	ft_put_object.c\
	ft_put_player.c\
	ft_win.c\
	ft_window_size.c\
	so_long.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./mlx
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

