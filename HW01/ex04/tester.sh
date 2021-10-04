# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisraely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:47:25 by aisraely          #+#    #+#              #
#    Updated: 2021/10/04 12:47:26 by aisraely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

echo "[bucketsort] Compiling the program..."
make

echo "TEST 1: Input is: 1"

if [ "`./bucketsort 1`" = "`seq 1`" ]
then
	echo -e "${GREEN}SUCCESS${NC}"
else
	echo -e "${RED}FAILURE${NC}"
fi

IN=$(seq 0 100 | sort -R)
echo "TEST 2: Input is:" $IN
OUT=$(./bucketsort $IN)

if [ "$OUT" = "`seq 0 100`" ]
then
	echo -e "${GREEN}SUCCESS${NC}"
else
	echo -e "${RED}FAILURE${NC}"
fi

IN=$(seq 0 9999 | sort -R)
echo "TEST 3: Input is:" $IN
OUT=$(./bucketsort $IN)

if [ "$OUT" = "`seq 0 9999`" ]
then
	echo -e "${GREEN}SUCCESS${NC}"
else
	echo -e "${RED}FAILURE${NC}"
fi

IN=$(jot -r 100)
echo "TEST 4: Input is:" $IN
echo "The output: "
echo $(./bucketsort $IN | tr "\n" " ")

echo "[bucketsort] Cleaning up..."
make fclean