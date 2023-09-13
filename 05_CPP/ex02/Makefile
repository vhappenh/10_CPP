NAME := toomanyforms

CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

CXX := c++

OBJ_P := obj/

SRC := main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp

OBJ := $(SRC:%.cpp=$(OBJ_P)%.o)

DEPS := $(SRC:%.cpp=$(OBJ_P)%.d)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_P)%.o:%.cpp | $(OBJ_P)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_P):
		mkdir -p obj

clean:
		$(RM) $(OBJ) $(DEPS)
		$(RM) -r $(OBJ_P) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re