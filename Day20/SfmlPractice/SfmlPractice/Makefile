SRCDIR=../SfmlPractice/SfmlPractice
INCLUDE=-I/opt/homebrew/include/

# Compilation Flags
CFLAGS=-std=c++11 $(INCLUDE)

#Linking Flags
LFLAGS=-L/opt/homebrew/lib -lsfml-graphics -lsfml-system -lsfml-window

CC=g++

.PHONY : all
all : game

#Lists of all object files to link together.
OBJS=main.o Ball.o

Ball.o : $(SRCDIR)/Ball.cpp $(SRCDIR)/Ball.h $(CC) $(CFLAGS) -c $<

main.o : $(SRCDIR)/main.cpp $(SRCDIR)/Ball.h $(CC) $(CFLAGS) -c $<

game : $(OBJS) $(CC) $(LFLAGS) -o game $(OBJS)
