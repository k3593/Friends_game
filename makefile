main: friends.o
		g++ -g -o main friends.o -lsfml-graphics -lsfml-window -lsfml-system
matrice.o:friends.cpp friends.hpp
		g++  -g -c friends.cpp
clean :
		rm -f *.o main
