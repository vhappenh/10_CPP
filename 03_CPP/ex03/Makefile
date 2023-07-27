NAME := borderlands

CFLAGS := -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow

CC := c++ -g

OBJ_P := ./obj/

vpath %.cpp src

SRC := main.cpp\
		ClapTrap.cpp\
		ScavTrap.cpp\
		FragTrap.cpp\
		DiamondTrap.cpp

OBJ := $(SRC:%.cpp=$(OBJ_P)%.o)

$(OBJ_P)%.o:%.cpp
		mkdir -p obj
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) -rd $(OBJ_P)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re