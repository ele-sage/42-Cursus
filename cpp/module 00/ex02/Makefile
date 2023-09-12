NAME	= Account
SRC		= src/Account.cpp src/tests.cpp
OBJ		= $(SRC:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror
INC		= -I includes

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	clang++ $(FLAGS) $(INC) -c $< -o $@
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
