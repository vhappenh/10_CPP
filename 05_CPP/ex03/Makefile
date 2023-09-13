NAME := ilovemyjob

CPPFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP -g

CXX := c++

OBJ_P := obj/

SRC := main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp\
		Intern.cpp

OBJ := $(SRC:%.cpp=$(OBJ_P)%.o)

DEPS := $(SRC:%.cpp=$(OBJ_P)%.d)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_P)%.o:%.cpp | $(OBJ_P)
		$(CXX) $(CPPFLAGS) -c $< -o $@

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