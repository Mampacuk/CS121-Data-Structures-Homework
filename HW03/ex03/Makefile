# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 17:23:02 by aisraely          #+#    #+#              #
#    Updated: 2021/10/25 18:55:12 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= odd_iterator

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

all: $(DFL)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o) 

$(DFL): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(DFL)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(DFL)

re: fclean all test

.PHONY: clean fclean re all test