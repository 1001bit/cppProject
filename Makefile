FLAGS := -Wall -Wextra -std=c++20 -ggdb
INCLUDE		:= -Iinclude
SOURCE		:= src/*.cpp src/Text/*
EXECUTABLE	:= bin/main

all: 
	g++ $(FLAGS) $(INCLUDE) $(SOURCE) -o $(EXECUTABLE)
