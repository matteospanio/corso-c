CC = gcc
FLAGS = -Wall -g -Werror
PROGRAM = coffe
OBJS = main.o coffe_machine.o

all: $(PROGRAM)

coffe_machine.o: coffe_machine.c
	$(CC) $(FLAGS) -c $< -o $@

main.o: main.c coffe_machine.h
	$(CC) $(FLAGS) -c $< -o $@

$(PROGRAM): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGRAM)
