# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 14:50:45 by aisraely          #+#    #+#              #
#    Updated: 2021/10/25 14:58:28 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "[remove_dupes] Compiling the program..."
make

i=1
while [ $i -le 5 ]
do
	jotarg=$(($x * 20))
	IN=$(jot -r $jotarg | sort -h)
	echo "TEST $i: Input is:" $IN
	./remove_dupes $IN | tr "\n" " "
	x=$(($x + 1))
done

echo "[vector_radix] Cleaning up..."
make fclean