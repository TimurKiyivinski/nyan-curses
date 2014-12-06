#CC = gcc or g++
CC = g++
#CFLAGS are compile flags such as -lm to include <math.h>
#or -std=c++0x for C++11
CFLAGS = -std=c++0x -lncurses
#TARGET is the name of your main file
TARGET = main
#OBJECTS = $(TARGET).o library1.o library.o, all the header files here
OBJECTS = $(TARGET).o Asteroid.o Coordinates.o Game.o Looks.o Nyan.o Screen.o Text.o

#Do not modify
$(TARGET) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET).bin

#%.c or %.cpp
%.o : %.cpp
		$(CC) $(CFLAGS) -c $<

clean:
	rm -rvf $(OBJECTS) $(TARGET).bin *~
