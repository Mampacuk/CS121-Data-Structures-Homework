# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 22:14:14 by aisraely          #+#    #+#              #
#    Updated: 2021/11/26 22:49:09 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "[unique_sort] Compiling the program..."
make

seq 1000 | sort -R | ./unique_sort

echo "[unique_sort] Cleaning up..."
make fclean