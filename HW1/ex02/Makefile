# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 13:08:17 by aisraely          #+#    #+#              #
#    Updated: 2021/09/04 19:21:05 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= palicount
TEST		= test

SRCS		= ft_count_palindromes.cpp main.cpp
TEST_SRCS	= ft_count_palindromes.cpp tester.cpp
OBJS		= $(SRCS:.cpp=.o)
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wextra -Werror

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

test: $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST)

clean:
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

.PHONY: clean fclean re all