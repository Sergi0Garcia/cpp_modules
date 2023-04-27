# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 09:59:27 by segarcia          #+#    #+#              #
#    Updated: 2023/04/27 13:31:10 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03
	
CC			= g++
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror -std=c++98

OBJDIR 		= .obj
FILES		= main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm Intern
SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADERS	= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

RED			= 	\e[31m
GREEN		=	\e[92;5;118m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(CURSIVE)$(GREEN)- Compiling ...\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@find . -name "*.txt" -type f -delete
	@printf "$(CURSIVE)$(RED)- Object files removed.$(RESET)\n"
	@printf "$(CURSIVE)$(RED)- files txt removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CURSIVE)$(RED)- Executable removed.$(RESET)\n"

re: fclean all