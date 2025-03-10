# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 13:11:49 by arissane          #+#    #+#              #
#    Updated: 2025/03/10 13:59:31 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap 

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
