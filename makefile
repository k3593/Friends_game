all : main

main : main.o gameElement.o player.o room.o appartment.o game.o menu.o door.o
	g++ -Wall -o main main.o gameElement.o room.o player.o appartment.o game.o menu.o door.o -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

gameElement.o : gameElement.cpp gameElement.hpp
	g++ -Wall -c gameElement.cpp

room.o : room.cpp room.hpp gameElement.hpp
	g++ -Wall -c room.cpp

door.o : door.cpp door.hpp gameElement.hpp
	g++ -Wall -c door.cpp

player.o : player.cpp player.hpp gameElement.hpp room.hpp
	g++ -Wall -c player.cpp

appartment.o : appartment.cpp appartment.hpp gameElement.hpp room.hpp player.hpp
	g++ -Wall -c appartment.cpp

game.o : game.cpp game.hpp appartment.hpp
	g++ -Wall -c game.cpp

menu.o : menu.cpp menu.hpp
	g++ -Wall -c menu.cpp

main.o: main.cpp gameElement.hpp player.hpp room.hpp appartment.hpp game.hpp menu.hpp door.hpp
	g++ -Wall -c main.cpp

clean:
	rm -f *.o

vclean: clean
	rm -f main
