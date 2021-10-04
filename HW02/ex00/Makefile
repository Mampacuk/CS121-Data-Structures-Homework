# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 13:37:35 by aisraely          #+#    #+#              #
#    Updated: 2021/10/04 14:29:47 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= dll

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