all : main

main : main.o gameElement.o player.o room.o appartment.o
	g++ -Wall -o main main.o gameElement.o player.o room.o appartment.o -lsfml-graphics -lsfml-window -lsfml-system

gameElement.o : gameElement.cpp gameElement.hpp
	g++ -Wall -c gameElement.cpp 
	
player.o : player.cpp player.hpp gameElement.hpp
	g++ -Wall -c player.cpp 
	
room.o : room.cpp room.hpp gameElement.hpp
	g++ -Wall -c room.cpp 
	
appartment.o : appartment.cpp appartment.hpp gameElement.hpp room.hpp player.hpp
	g++ -Wall -c appartment.cpp 

main.o: main.cpp gameElement.hpp player.hpp room.hpp appartment.hpp
	g++ -Wall -c main.cpp

clean:
	rm -f *.o

vclean: clean
	rm -f main
