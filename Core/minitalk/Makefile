# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 12:33:49 by ele-sage          #+#    #+#              #
#    Updated: 2023/06/15 09:55:12 by ele-sage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
SERVER		=	srcs/server.c \
				srcs/utils.c

CLIENT		=	srcs/client.c \
				srcs/utils.c

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

# Sources and objects
SERVER_SRC	=	$(SERVER)
SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

NAME		=	server client

COMP_START	=	echo "\033[0;33mCompiling $(NAME)...\033[0m"

COMP_END	=	echo "\033[0;32m$(NAME) compiled successfully!\033[0m"

# ------------------------------ Rules ------------------------------
all: $(NAME)

$(NAME): libft comp_start ft_server ft_client comp_end

comp_end:
	@$(COMP_END)

comp_start:
	@$(COMP_START)
	@$(LIBFT)

ft_server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)

ft_client: $(CLIENT_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@cd libft && make fclean

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all server client clean fclean re libft