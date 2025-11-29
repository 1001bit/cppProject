FLAGS := -Wall -Wextra -std=c++20 -ggdb
 
EXECUTABLE	:= main
INCLUDE		:= -Iinclude
SOURCE		:= src/*.cpp

all: 
	g++ $(FLAGS) $(INCLUDE) $(SOURCE) -o bin/$(EXECUTABLE) $(LIBRARIES)