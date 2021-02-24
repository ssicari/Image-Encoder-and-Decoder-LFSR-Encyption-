CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11
OBJECTS = FibLFSR.o PhotoMagic.o
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system


all: PhotoMagic

PhotoMagic: $(OBJECTS)
	$(CC) $(CFLAGS) -o PhotoMagic $(OBJECTS) $(SFMLFLAGS)

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

PhotoMagic.o: PhotoMagic.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o

clean:
	rm PhotoMagic *.o
