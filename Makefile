all:
	gcc -Wall -Werror -g main.c baralho.c carta.c -o ex -lm

run:
	./ex

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./ex
