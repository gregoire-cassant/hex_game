game: game.o main.o menu.o board.o types.o ia.o save.o
	gcc -o game game.o main.o menu.o board.o types.o ia.o save.o


%.o: %.c
	gcc -Werror -Wextra -c $<

clean:
	rm game.o main.o menu.o board.o types.o ia.o save.o game
	rm .hex-save_*
