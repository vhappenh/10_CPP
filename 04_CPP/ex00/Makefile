NAME := animals

CFLAGS := -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow -MMD -MP

CC := c++ -g

OBJ_P := ./obj/

vpath %.cpp src

SRC := main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp

OBJ := $(SRC:%.cpp=$(OBJ_P)%.o)

DEPS := $(SRC:%.cpp=$(OBJ_P)%.d)

$(OBJ_P)%.o:%.cpp
		mkdir -p obj
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ) $(DEPS)
		$(RM) -rd $(OBJ_P) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re