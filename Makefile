FLAGS := -Wall -Wextra -std=c++20 -ggdb

LIBRARIES	:= 
EXECUTABLE	:= main
LIBPATH		:= GGE/lib/SFML
INCLUDE		:= -Iinclude
SOURCE		:= src/*.cpp

all: 
	g++ $(FLAGS) $(INCLUDE) -L$(LIBPATH)/linux $(SOURCE) -o bin/$(EXECUTABLE) $(LIBRARIES)
win:
	g++ $(FLAGS) $(INCLUDE) -L$(LIBPATH)/win $(SOURCE) -o bin/$(EXECUTABLE) $(LIBRARIES)