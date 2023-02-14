OBJECTS = main.o
NAME = DONUT_WII

build: $(OBJECTS)
cc $(OBJECTS) -o $(NAME)