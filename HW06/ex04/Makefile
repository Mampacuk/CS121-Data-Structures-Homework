# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:07:30 by aisraely          #+#    #+#              #
#    Updated: 2021/11/24 16:07:30 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= xor
NAME2		= poly

SRCS1		= xor_mod_chain.cpp
SRCS2		= poly_mad_prob.cpp
OBJS1		= $(SRCS1:.cpp=.o)
OBJS2		= $(SRCS2:.cpp=.o)
CC			= c++
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

all: $(NAME1) $(NAME2)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o) 

$(NAME1): $(OBJS1)
	@$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2): $(OBJS2)
	@$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

clean:
	@$(RM) $(OBJS1)
	@$(RM) $(OBJS2)

fclean: clean
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)

re: fclean all

.PHONY: clean fclean re all