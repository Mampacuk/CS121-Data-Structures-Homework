# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 23:37:00 by aisraely          #+#    #+#              #
#    Updated: 2021/11/10 23:37:00 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DFL			= grandchildren

SRCS		= ${wildcard *.cpp}
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
LIBFT		= ../../libft/libft.a

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

re: fclean all

.PHONY: clean fclean re all