#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

echo "[radixsort] Compiling the program..."
make

echo "TEST 1: Input is: 1"

if [ "`./radixsort 1`" = "`seq 1`" ]
then
	echo -e "${GREEN}SUCCESS${NC}"
else
	echo -e "${RED}FAILURE${NC}"
fi

IN=$(seq 0 100 | sort -R)
echo "TEST 2: Input is:" $IN
OUT=$(./radixsort $IN)

if [ "$OUT" = "`seq 0 100`" ]
then
	echo -e "${GREEN}SUCCESS${NC}"
else
	echo -e "${RED}FAILURE${NC}"
fi

IN=$(seq 0 9999 | sort -R)
echo "TEST 3: Input is:" $IN
OUT=$(./radixsort $IN)

if [ "$OUT" = "`seq 0 9999`" ]
then
	echo -e "${GREEN}SUCCESS${NC}"
else
	echo -e "${RED}FAILURE${NC}"
fi

IN=$(jot -r 100)
echo "TEST 4: Input is:" $IN
echo "The output: "
echo $(./radixsort $IN | tr "\n" " ")

echo "[radixsort] Cleaning up..."
make fclean