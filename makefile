pmain : player_main.c player.o
	gcc -o pmain player_main.c player.o
smain : server_main.c player.o
	gcc -o smain server_main.c player.o

player.o : player.c player.h
	gcc -c player.c -o player.o

clean : 
	rm *.o pmain smain
