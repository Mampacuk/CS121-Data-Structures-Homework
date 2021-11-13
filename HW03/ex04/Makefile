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
RM			= rm -rf

all: $(DFL)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o) 

$(DFL): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(DFL)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(DFL)

re: fclean all

.PHONY: clean fclean re all