# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 10:27:33 by segarcia          #+#    #+#              #
#    Updated: 2023/03/27 10:15:01 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = contact
SRC = Contact.cpp 		\
	  Phonebook.cpp  	\
	  main.cpp
OBJ = $(SRC:.cpp=.o)

CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
