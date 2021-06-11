CPP=g++
LD=g++
RM=rm -f
CFLAGS=-Wall -std=c++17
LDFLAGS=-Wall -std=c++17

all : main tests_catch

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

# Tests

#tests_catch: tests_catch_player.o player.o tests_catch_rectangle.o rectangle.o
	#$(LD) -o tests_catch tests_catch_player.o player.o tests_catch_rectangle.o rectangle.o


#tests_catch_player.o: tests_catch_player.cpp player.hpp gameElement.hpp room.hpp appartment.hpp catch.hpp
	#$(CPP) -c tests_catch_point.cpp

#tests_catch_rectangle.o: tests_catch_rectangle.cpp rectangle.hpp catch.hpp
#	$(CPP) -c tests_catch_rectangle.cpp*/

clean:
	rm -f *.o

vclean: clean
	rm -f main
