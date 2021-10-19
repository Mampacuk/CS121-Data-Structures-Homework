# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 17:23:39 by aisraely          #+#    #+#              #
#    Updated: 2021/10/19 17:56:49 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

echo "[vector_radix] Compiling the program..."
make

echo "TEST 1: Input is: 1"

if [ "`./vector_radix 1`" = "`seq 1`" ]
then
	echo "${GREEN}SUCCESS${NC}"
else
	echo "${RED}FAILURE${NC}"
fi

IN=$(seq 0 100 | sort -R)
echo "TEST 2: Input is:" $IN
OUT=$(./vector_radix $IN)

if [ "$OUT" = "`seq 0 100`" ]
then
	echo "${GREEN}SUCCESS${NC}"
else
	echo "${RED}FAILURE${NC}"
fi

IN=$(seq 0 9999 | sort -R)
echo "TEST 3: Input is:" $IN
OUT=$(./vector_radix $IN)

if [ "$OUT" = "`seq 0 9999`" ]
then
	echo "${GREEN}SUCCESS${NC}"
else
	echo "${RED}FAILURE${NC}"
fi

IN=$(jot -r 100)
echo "TEST 4: Input is:" $IN
echo "The output: "
echo $(./vector_radix $IN | tr "\n" " ")

echo "[vector_radix] Cleaning up..."
make fclean