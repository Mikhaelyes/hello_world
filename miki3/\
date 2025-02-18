LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: kosm

kosm: Vector2D.o Ship.o Planet.o main.o
    g++ Vector2D.o Ship.o Planet.o main.o $(LFLAGS) -o kosm

Vector2D.o: Vector2D.cpp
    g++ -c Vector2D.cpp

Ship.o: Ship.cpp
    g++ -c Ship.cpp

Planet.o: Planet.cpp
    g++ -c Planet.cpp

main.o: main.cpp
    g++ -c main.cpp


