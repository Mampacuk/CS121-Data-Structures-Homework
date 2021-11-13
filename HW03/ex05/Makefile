# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 21:40:09 by aisraely          #+#    #+#              #
#    Updated: 2021/10/26 23:20:38 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= sorted_iter

SRCS		= main.cpp StringArrayPositionalList.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ../../libft/libft.a
RM			= rm -rf

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

fclean: clean
	@$(RM) $(DFL)

re: fclean all test

.PHONY: clean fclean re all test