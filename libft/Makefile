# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 09:33:38 by lmorais-          #+#    #+#              #
#    Updated: 2023/12/01 09:33:54 by lmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes
RM = rm -rf
NAME = libft.a
OBJ_DIR = obj

SRCS = ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_format.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_print_c.c\
	ft_print_di.c\
	ft_print_p.c\
	ft_print_s.c\
	ft_print_u.c\
	ft_print_x.c\
	ft_printf.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	get_next_line.c\
	get_next_line_utils.c
	
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(OBJ_DIR) $(OBJ_DIR)/$(NAME)


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ_DIR) 
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re










