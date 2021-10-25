# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 17:23:02 by aisraely          #+#    #+#              #
#    Updated: 2021/10/25 16:48:04 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= dllvector_radix

SRCS		= main.cpp ft_vector_radix_sort.cpp
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