# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 16:47:26 by aisraely          #+#    #+#              #
#    Updated: 2021/10/04 17:23:37 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= office

SRCS		= main.cpp Student.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wextra -Werror -Wall
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

re: fclean all

.PHONY: clean fclean re all