# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 14:50:45 by aisraely          #+#    #+#              #
#    Updated: 2021/10/25 15:04:48 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "[remove_dupes] Compiling the program..."
make

i=1
while [ $i -le 5 ]
do
	jotarg=$(expr "20" "*" "$i")
	IN=$(jot -r $jotarg | sort -h)
	echo "TEST $i: Input is:" $IN
	./remove_dupes $IN
	i=$(($i + 1))
	printf "\n"
done

echo "[remove_dupes] Cleaning up..."
make fclean