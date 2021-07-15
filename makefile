C = gcc
CFLAGS = -std=c11

get: getch-linux.c getchar.c
	$(C) $(CFLAGS) getch-linux.c -o getch-linux  -l curses
	$(C) $(CFLAGS) getchar.c -o getchar
clean:
	rm  getch-linux getchar