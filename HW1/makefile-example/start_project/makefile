all: main

main: main.o lib.o square.o
	g++ main.o lib.o square.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

square.o: square.cpp
	g++ -c square.cpp -o square.o

lib.o: lib.cpp
	g++ -c lib.cpp -o lib.o

clean:
	rm -f *.o main

install:
	cp main /tmp
