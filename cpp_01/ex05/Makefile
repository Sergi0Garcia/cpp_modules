# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 09:59:27 by segarcia          #+#    #+#              #
#    Updated: 2023/04/05 12:46:46 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harl
	
CC			= g++
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror -std=c++98

OBJDIR 		= .obj
FILES		= main Harl
SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADERS		= Harl.hpp

RED			= 	\e[31m
PURPLE		= 	\e[95m
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
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
	@printf "$(CURSIVE)$(RED)- Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CURSIVE)$(RED)- Executable removed.$(RESET)\n"

re: fclean all