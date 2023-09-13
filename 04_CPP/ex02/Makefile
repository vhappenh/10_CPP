NAME := animals

CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP

CXX := c++ -g

OBJ_P := ./obj/

vpath %.cpp src

SRC := main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		Brain.cpp

OBJ := $(SRC:%.cpp=$(OBJ_P)%.o)

DEPS := $(SRC:%.cpp=$(OBJ_P)%.d)

$(OBJ_P)%.o:%.cpp
		mkdir -p obj
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ) $(DEPS)
		$(RM) -rd $(OBJ_P) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re