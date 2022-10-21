game: game.o main.o menu.o board.o types.o ia.o
	gcc -o game game.o main.o menu.o board.o types.o ia.o


%.o: %.c
	gcc -Werror -Wextra -c $<

clean:
	rm game.o main.o menu.o board.o types.o ia.o game
