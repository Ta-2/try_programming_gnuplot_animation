main: main.o
	g++ -Wall -o main main.o

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm *.o *.exe main *.gch

all:
	main
