# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 09:17:14 by schahid           #+#    #+#              #
#    Updated: 2023/05/14 09:58:56 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RPN
SRC= RPN.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
		@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME) 
		@echo "RPN compiled successfully ✅"
		
%.o: %.cpp
		@$(CPP) $(CPPFLAGS) -c $<

all: $(NAME)

clean:
		@rm -rf $(OBJ)
		@echo "RPN object files cleaned successfully 🗑"
fclean:
		@rm -rf $(OBJ)
		@rm -rf $(NAME)
		@echo "RPN object files and RPN cleaned successfully 🗑"

re: fclean all