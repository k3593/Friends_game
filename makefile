# CPP=g++
# LD=g++
# RM=rm -f
# CFLAGS=-Wall -std=c++17
# LDFLAGS=-Wall -std=c++17

# all : main test_catch
# #all : main

# main : main.o gameElement.o player.o room.o appartment.o game.o menu.o door.o objet.o
# 	g++ -Wall -o main main.o gameElement.o room.o player.o appartment.o game.o menu.o door.o objet.o -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

# gameElement.o : gameElement.cpp gameElement.hpp
# 	g++ -Wall -c gameElement.cpp

# room.o : room.cpp room.hpp gameElement.hpp objet.hpp
# 	g++ -Wall -c room.cpp

# door.o : door.cpp door.hpp gameElement.hpp
# 	g++ -Wall -c door.cpp

# player.o : player.cpp player.hpp gameElement.hpp room.hpp objet.hpp
# 	g++ -Wall -c player.cpp

# appartment.o : appartment.cpp appartment.hpp gameElement.hpp room.hpp player.hpp objet.hpp
# 	g++ -Wall -c appartment.cpp

# game.o : game.cpp game.hpp appartment.hpp objet.hpp
# 	g++ -Wall -c game.cpp

# menu.o : menu.cpp menu.hpp
# 	g++ -Wall -c menu.cpp

# objet.o : objet.cpp objet.hpp gameElement.hpp
# 	g++ -Wall -c objet.cpp

# main.o: main.cpp gameElement.hpp player.hpp room.hpp appartment.hpp game.hpp menu.hpp door.hpp objet.hpp
# 	g++ -Wall -c main.cpp

# # Tests
# test_catch: test_catch_player.o player.o gameElement.o room.o appartment.o
# 	$(LD) -o test_catch test_catch_player.o player.o 

# test_catch_player.o: test_catch_player.cpp player.hpp gameElement.hpp room.hpp appartment.hpp catch.hpp
# 	$(CPP) -c test_catch_player.cpp

# #test_catch_rectangle.o: test_catch_rectangle.cpp rectangle.hpp catch.hpp
# #	$(CPP) -c test_catch_rectangle.cpp*/

# clean:
# 	rm -f *.o test_catch

# vclean: clean
# 	rm -f main


#VARIABLES
# compiler
CXX	:= g++
# compiler flags
CXXFLAGS := -g -Wall
# any -I options to the compiler
INCLUDES := 
# Libraries we need to link in
LIBS     := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# All of the objects we want to build
# OBJECTS  := main.o Game.o Player.o Enemy.o Projectile.o SolidMobile.o MobileObject.o GraphicObject.o 
#folder with source code
SRC_DIR := ./Game
#folder to keep the .o files
OBJ_DIR := ./Game
#list of all source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
#list of all .o files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

#The executable we want to build
EXEC := main



# For the unit testing
#folder with the test source code
TEST_DIR := ./Test
#folder to keep .o files for tests
TEST_OBJ_DIR := ./Test
#list of all test cpp files
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
#list of all .o files from cpp test files
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp, $(TEST_OBJ_DIR)/%.o, $(TEST_FILES))
#TEST_SRC_OBJ_FILES := $(patsubst $(TEST_DIR)/test_catch_%.cpp, $(OBJ_DIR)/%.o, $(TEST_FILES))
#list of all .o files from source code, excepted main.o because catch2 makes a new one
TEST_SRC_OBJ_FILES := $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES))

#The test executable we want to build
TEST_EXEC := test_catch


all : $(EXEC) #$(TEST_EXEC)

test : $(TEST_EXEC)

# Source compilation and building
$(EXEC): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
#$(CXX) $(INCLUDES) $(CXXFLAGS) -c $(input) -o $(target)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@



# Tests compilation and building
$(TEST_EXEC): $(TEST_OBJ_FILES) $(TEST_SRC_OBJ_FILES)
	$(CXX) $^ -o $@ $(LIBS)

$(TEST_OBJ_DIR)/test_catch_%.o: $(TEST_DIR)/test_catch_%.cpp $(SRC_DIR)/%.hpp $(TEST_DIR)/catch.hpp
#$(CXX) $(INCLUDES) $(CXXFLAGS) -c $(input) -o $(target)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@



clean: 
	rm -rf *.o
#	rm -rf $(OBJ_DIR)/*.o
#	rm -rf $(TEST_OBJ_DIR)/*.o
	rm -rf $(EXEC)
	rm -rf $(TEST_EXEC)


cleanExec :
	rm -rf $(EXEC)

# $^ : name of all listed files
# $@ : name of the first output file
# $< : name of the first input file

