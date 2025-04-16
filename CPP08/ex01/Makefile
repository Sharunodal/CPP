# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 10:36:30 by arissane          #+#    #+#              #
#    Updated: 2025/04/16 12:29:03 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp Span.cpp
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
