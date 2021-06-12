 CPP=g++
 LD=g++
 RM=rm -f
 CFLAGS=-Wall -std=c++17
 LDFLAGS=-Wall -std=c++17

all : main 
test : test_catch

main : main.o gameElement.o player.o room.o appartment.o game.o menu.o door.o objet.o
	g++ -Wall -o main main.o gameElement.o room.o player.o appartment.o game.o menu.o door.o objet.o -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

gameElement.o : gameElement.cpp gameElement.hpp
	g++ -Wall -c gameElement.cpp

room.o : room.cpp room.hpp gameElement.hpp objet.hpp
	g++ -Wall -c room.cpp

door.o : door.cpp door.hpp gameElement.hpp
	g++ -Wall -c door.cpp

player.o : player.cpp player.hpp gameElement.hpp room.hpp objet.hpp
	g++ -Wall -c player.cpp

appartment.o : appartment.cpp appartment.hpp gameElement.hpp room.hpp player.hpp objet.hpp
	g++ -Wall -c appartment.cpp

game.o : game.cpp game.hpp appartment.hpp objet.hpp
	g++ -Wall -c game.cpp

menu.o : menu.cpp menu.hpp
	g++ -Wall -c menu.cpp

objet.o : objet.cpp objet.hpp gameElement.hpp
	g++ -Wall -c objet.cpp

main.o: main.cpp gameElement.hpp player.hpp room.hpp appartment.hpp game.hpp menu.hpp door.hpp objet.hpp
	g++ -Wall -c main.cpp

# Tests
test_catch: test_catch_room.o test_catch_player.o test_catch_appartment.o test_catch_door.o player.o gameElement.o room.o appartment.o objet.o door.o
	$(LD) -o test_catch test_catch_room.o test_catch_player.o test_catch_appartment.o test_catch_door.o player.o gameElement.o room.o appartment.o objet.o door.o -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
	
test_catch_player.o: test_catch_player.cpp player.hpp gameElement.hpp room.hpp appartment.hpp catch.hpp objet.hpp
	$(CPP) -c test_catch_player.cpp

test_catch_appartment.o: test_catch_appartment.cpp player.hpp gameElement.hpp room.hpp appartment.hpp catch.hpp objet.hpp
	$(CPP) -c test_catch_appartment.cpp

test_catch_door.o: test_catch_door.cpp door.hpp 
	$(CPP) -c test_catch_door.cpp

test_catch_room.o: test_catch_room.cpp door.hpp objet.hpp room.hpp
	$(CPP) -c test_catch_room.cpp

clean:
	rm -f *.o test_catch

vclean: clean
	rm -f main


