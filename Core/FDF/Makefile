# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 12:33:49 by ele-sage          #+#    #+#              #
#    Updated: 2023/02/28 15:35:31 by ele-sage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = 	main.c		init.c			map_parsing.c		ft_free.c \
		draw.c		draw_utils.c	color.c  			color_utils.c \
		projection.c	controls.c  
		

SRCS_DIR = srcs/
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIRS = objs/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIRS)%.o)
DEPS = $(SRCS:%.c=%.d)

LIBFT = libft/libft.a
LIBMLX = mlx/libmlx42.a
LIBGLFW = mlx/libglfw3.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -MMD -Iinclude -g -Wunreachable-code -Ofast
LDFLAGS = -Llibft/ -Lmlx/
LDLIBS = -framework OpenGL -framework AppKit -framework IOKit -lft -lmlx42 -lglfw3

all: lib libmlx $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX) $(LIBGLFW)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJS)

$(OBJS_DIRS)%.o:$(SRCS_DIR)%.c
	@$(MAKE) $(OBJS_DIRS)
	$(CC) $(CFLAGS) -c -o $@ $<

lib:
	@$(MAKE) -s -C libft/

libmlx:
	@$(MAKE) -s -C mlx/
	
clean:
	@$(MAKE) -s -C mlx/ clean
	@$(MAKE) -s -C libft/ clean
	@rm -f $(OBJS) $(DEPS)

fclean: clean
	@$(MAKE) -C libft/ $@
	@$(MAKE) -C mlx/ $@
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
-include $(DEPS)
