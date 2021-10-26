# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 21:40:09 by aisraely          #+#    #+#              #
#    Updated: 2021/10/26 21:40:32 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= str_list

SRCS		= main.cpp StringArrayPositionalList.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wall -Wextra -Werror

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

re: fclean all test

.PHONY: clean fclean re all test