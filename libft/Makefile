# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 14:37:00 by aisraely          #+#    #+#              #
#    Updated: 2021/09/19 19:58:31 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= g++
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)
AR		= ar rc

ifeq ($(OS), Windows_NT)
	RM		= del /f >nul 2>&1
else
	RM		= rm -rf
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS)

ifeq ($(OS), Windows_NT)
fclean: clean
	@$(RM) $(addsuffix .exe,$(NAME))
else
fclean: clean
	@$(RM) $(NAME)
endif

re: fclean all

.PHONY: clean fclean re all