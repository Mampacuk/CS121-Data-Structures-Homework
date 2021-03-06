# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:47:32 by aisraely          #+#    #+#              #
#    Updated: 2021/10/19 20:53:04 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

echo "[lstsort] Compiling the program..."
make

echo "TEST 1: Input is: 1"

if [ "`./lstsort 1`" = "`seq 1`" ]
then
	echo "${GREEN}SUCCESS${NC}"
else
	echo "${RED}FAILURE${NC}"
fi

IN=$(seq 0 100 | sort -R)
echo "TEST 2: Input is:" $IN
OUT=$(./lstsort $IN)

if [ "$OUT" = "`seq 0 100`" ]
then
	echo "${GREEN}SUCCESS${NC}"
else
	echo "${RED}FAILURE${NC}"
fi

IN=$(seq 0 9999 | sort -R)
echo "TEST 3: Input is:" $IN
OUT=$(./lstsort $IN)

if [ "$OUT" = "`seq 0 9999`" ]
then
	echo "${GREEN}SUCCESS${NC}"
else
	echo "${RED}FAILURE${NC}"
fi

IN=$(jot -r 100)
echo "TEST 4: Input is:" $IN
echo "The output: "
echo $(./lstsort $IN | tr "\n" " ")

echo "[lstsort] Cleaning up..."
make fclean