all : main

main : main.o friends.o
	g++ -Wall -o main main.o friends.o -lsfml-graphics -lsfml-window -lsfml-system

friends.o : friends.cpp friends.hpp
	g++ -Wall -c friends.cpp 

main.o: main.cpp friends.hpp 
	g++ -Wall -c main.cpp

clean:
	rm -f *.o

vclean: clean
	rm -f main
