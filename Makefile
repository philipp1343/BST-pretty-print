CC = clang++
CFLAGS = -Wall -std=c++11

all: theProgram

run: theProgram
	./theProgram
theProgram: main.o TheBST.o
	$(CC) $(CFLAGS) main.o TheBST.o -o theProgram

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

TheBST.o: TheBST.cpp TheBST.h
	$(CC) $(CFLAGS) -c TheBST.cpp

clean:
	rm -f *.o theProgram
