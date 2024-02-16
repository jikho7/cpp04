NAME = ex02
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ := $(SRC:%.cpp=%.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = g++

all : $(NAME)

.c.o:
	${CC} ${CXXLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
