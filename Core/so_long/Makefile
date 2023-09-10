# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:50:12 by ele-sage          #+#    #+#              #
#    Updated: 2023/01/26 15:55:41 by ele-sage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INC			=	-I./inc
LDLIBS		=	-lmlx -framework OpenGl -framework AppKit
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/so_long.c src/read_file.c src/map_verification.c src/utils.c src/init_map.c \
				src/valid_path.c src/valid_path_utils.c

all:		$(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(INC) -fsanitize=address -o $@ $^ $(LIB)

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re


NAME = fdf
SRCS = ft_split_numbers.c \
        main.c \
        map.c \
        window.c
SRCS_DIR = srcs/
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIRS = objs/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIRS)%.o)
DEPS = $(SRCS:%.c=%.d)
LIB_DIRS = libft/ minilibx_macos/
INCLUDE_DIR = include/
CC = gcc
IQUOTES = $(addprefix -iquote, $(INCLUDE_DIR) $(LIB_DIRS))
CFLAGS = -Wall -Werror -Wextra -MMD $(IQUOTES) -g -fsanitize=address
LDFLAGS = $(addprefix -L, $(LIB_DIRS))
LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit 
# -lm pour maths
all: $(NAME)
$(NAME): $(OBJS)
    @for dir in $(LIB_DIRS); do \
        $(MAKE) -C $$dir ; \
    done
    $(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJS)
$(OBJS_DIRS)%.o:$(SRCS_DIR)%.c
    @mkdir -p $(OBJS_DIRS)
    $(CC) $(CFLAGS) -c -o $@ $<
clean:
    @for dir in $(LIB_DIRS); do \
        $(MAKE) -C $$dir $@; \
    done
    @rm -f $(OBJS) $(DEPS)
fclean: clean
    @$(MAKE) -C libft/ $@
    rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include $(DEPS)