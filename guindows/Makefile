CC = gcc
OBJECTS = guindows.o main.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) 

main.o: main.c guindows.c guindows.h
guindows.o: guindows.c guindows.h

clean :
	rm main *.o
