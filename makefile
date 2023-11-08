CC = gcc
CFLAGS = -Wall -g 
HEADERS = commands.h history.h exit.h definitions.h directory.h
SOURCES = main.c history.c commands.c exit.c
OBJ = main.o commands.o history.o exit.o directory.o

myshell: $(OBJ)
	$(CC) $(CFLAGS) -o myshell $(OBJ)

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

commands.o: commands.c commands.h
	$(CC) $(CFLAGS) -c commands.c

history.o: history.c history.h
	$(CC) $(CFLAGS) -c history.c

exit.o: exit.c exit.h
	$(CC) $(CFLAGS) -c exit.c

directory.o: directory.c directory.h
	$(CC) $(CFLAGS) -c directory.c

clean:
	rm -f $(OBJ) myshell
