# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 12:16:16 by ele-sage          #+#    #+#              #
#    Updated: 2023/01/05 18:43:15 by ele-sage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
INCLUDE_DIR = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

SRC_FILES = dp_algo.c file_manip.c free.c ft_atoi.c init_map.c is_map_valid.c main.c print_map.c util.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR),$(SRC_FILES))
OBJS = $(addprefix $(SRCS_DIR),$(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re