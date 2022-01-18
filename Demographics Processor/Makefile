CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g
MAIN = runner
OBJS = filestuff.o liststuff.o main.o mem.o spfunctions.o stringstuff.o commands.o

all : $(MAIN)

$(MAIN) : $(OBJS) main.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

filestuff.o : filestuff.c main.h
	$(CC) $(CFLAGS) -c filestuff.c

liststuff.o : liststuff.c main.h
	$(CC) $(CFLAGS) -c liststuff.c

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

mem.o: mem.c main.h
	$(CC) $(CFLAGS) -c mem.c

spfunctions.o: spfunctions.c main.h
	$(CC) $(CFLAGS) -c spfunctions.c

stringstuff.o: stringstuff.c main.h
	$(CC) $(CFLAGS) -c stringstuff.c

commands.o: commands.c main.h
	$(CC) $(CFLAGS) -c commands.c




clean :
	rm *.o $(MAIN) core
