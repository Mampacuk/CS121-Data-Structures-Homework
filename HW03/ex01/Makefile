# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 21:06:04 by aisraely          #+#    #+#              #
#    Updated: 2021/10/19 21:06:41 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= remove_dupes

SRCS		= main.cpp ft_remove_dupes.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ../../libft/libft.a

ifeq ($(OS), Windows_NT)
	RM		= del /f >nul 2>&1
else
	RM		= rm -rf
endif

all: $(DFL)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o) 

$(LIBFT):
	@$(MAKE) -C ../../libft

$(DFL): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(DFL)

clean:
	@$(MAKE) -C ../../libft fclean
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