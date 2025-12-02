FLAGS := -Wall -Wextra -std=c++23 -ggdb
INCLUDE		:= -Iinclude
SOURCE		:= src/*.cpp src/**/*
EXECUTABLE	:= bin/main

all: 
	g++ $(FLAGS) $(INCLUDE) $(SOURCE) -o $(EXECUTABLE)