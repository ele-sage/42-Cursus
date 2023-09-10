# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 04:43:27 by ele-sage          #+#    #+#              #
#    Updated: 2023/09/10 04:43:35 by ele-sage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Phonebook
SRC		= src/Phonebook.cpp src/Contact.cpp src/main.cpp
OBJ		= $(SRC:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -I./includes -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
