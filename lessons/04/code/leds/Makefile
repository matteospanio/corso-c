CC=gcc
FLAGS=-Wall -g -Werror
PROGRAM=leds
OBJS=main.o led_controller.o

all: $(PROGRAM)

led_controller.o: led_controller.c
	$(CC) $(FLAGS) -c $< -o $@

main.o: main.c led_controller.h
	$(CC) $(FLAGS) -c $< -o $@

$(PROGRAM): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGRAM)
