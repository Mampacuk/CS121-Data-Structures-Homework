# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 18:39:19 by aisraely          #+#    #+#              #
#    Updated: 2021/10/08 18:39:26 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= array_deque

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wextra -Werror -Wall

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