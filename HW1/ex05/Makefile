# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 15:37:54 by aisraely          #+#    #+#              #
#    Updated: 2021/09/05 15:37:54 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= mazewalker

SRCS		= ft_traverse_maze.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -g -Wall -Wextra -Werror

ifeq ($(OS), Windows_NT)
	RM		= del /f >nul 2>&1
else
	RM		= rm -rf
endif

all: $(DFL)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o) 

$(DFL): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(DFL)

clean:
	@$(RM) $(OBJS)

ifeq ($(OS), Windows_NT)
fclean: clean
	@$(RM) $(addsuffix .exe,$(DFL))
else
fclean: clean
	@$(RM) $(DFL)
endif

re: fclean all

.PHONY: clean fclean re all