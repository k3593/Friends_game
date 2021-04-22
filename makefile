all : main

main : main.o 
	g++ -Wall -o main main.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp friends.hpp 
	g++ -Wall -c main.cpp

clean:
	rm -f *.o

vclean: clean
	rm -f main
