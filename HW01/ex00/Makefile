# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 17:39:24 by aisraely          #+#    #+#              #
#    Updated: 2021/09/19 14:42:01 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= sorting
TEST		= test

SRCS		= ft_selection_sort.cpp ft_insertion_sort.cpp main.cpp
TEST_SRCS	= ft_selection_sort.cpp ft_insertion_sort.cpp tester.cpp
OBJS		= $(SRCS:.cpp=.o)
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)
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

$(DFL): $(OBJS)
	@$(MAKE) -C ../../libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(DFL)

test: $(TEST_OBJS)
	@$(MAKE) -C ../../libft
	@$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFT) -o $(TEST)

clean:
	@$(MAKE) -C ../../libft fclean
	@$(RM) $(OBJS)
	@$(RM) $(TEST_OBJS)

ifeq ($(OS), Windows_NT)
fclean: clean
	@$(RM) $(addsuffix .exe,$(DFL))
	@$(RM) $(addsuffix .exe,$(TEST))
else
fclean: clean
	@$(RM) $(DFL)
	@$(RM) $(TEST)
endif

re: fclean all

.PHONY: clean fclean re all test