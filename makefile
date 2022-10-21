game: game.o main.o menu.o board.o types.o ia.o
	gcc -o game game.o main.o menu.o board.o types.o ia.o


%.o: %.c
	gcc -c -c $<

clean:
	rm *.o game
