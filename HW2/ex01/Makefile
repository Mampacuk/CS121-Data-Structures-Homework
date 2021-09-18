# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 18:30:33 by aisraely          #+#    #+#              #
#    Updated: 2021/09/18 18:30:34 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= stepper
TEST		= test

SRCS		= ft_check_step.cpp ft_find_step.cpp main.cpp
TEST_SRCS	= ft_check_step.cpp ft_find_step.cpp tester.cpp
OBJS		= $(SRCS:.cpp=.o)
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)
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

.PHONY: clean fclean re all test