# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 09:35:30 by schahid           #+#    #+#              #
#    Updated: 2023/05/14 10:39:44 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= PmergeMe
SRC= PmergeMe.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
		@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME) 
		@echo "PmergeMe compiled successfully ✅"
		
%.o: %.cpp
		@$(CPP) $(CPPFLAGS) -c $<

all: $(NAME)

clean:
		@rm -rf $(OBJ)
		@echo "PmergeMe object files cleaned successfully 🗑"
fclean:
		@rm -rf $(OBJ)
		@rm -rf $(NAME)
		@echo "PmergeMe object files and PmergeMe cleaned successfully 🗑"

re: fclean all