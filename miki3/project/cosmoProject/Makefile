EXEC_NAME = sfml-app.out
ARGS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o calc.o Planet.o Ship.o Vector2D.o
	gcc $(ARGS) -o exec/$(EXEC_NAME) $^

%.o: %.cpp
	gcc -c $(ARGS) -o $@ $^

cleanup:
	rm *.o
