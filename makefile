player : main.c player.o
	gcc -o player main.c player.o

player.o : player.c player.h
	gcc -c player.c -o player.o

clean : 
	rm *.o player
