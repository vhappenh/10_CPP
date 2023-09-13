NAME := fixed

CXXFLAGS := -Wall -Werror -Wextra -std=c++98

CXX := c++ -g

OBJ_P := ./obj/

vpath %.cpp src

SRC := main.cpp\
		Fixed.cpp\

OBJ := $(SRC:%.cpp=$(OBJ_P)%.o)

$(OBJ_P)%.o:%.cpp
		mkdir -p obj
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) -rd $(OBJ_P)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re