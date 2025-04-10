# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 11:04:52 by arissane          #+#    #+#              #
#    Updated: 2025/04/10 11:06:03 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp Serializer.cpp
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
