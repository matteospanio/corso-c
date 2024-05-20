CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Werror -Wextra
PROG = secrets

ifeq ($(DEBUG),1)
	CFLAGS += -DDEBUG -g
endif

SOL = solution.c
MAIN_SRC = secrets.c

OBJS = solution.o secrets.o

all: $(PROG)

solution.o: $(SOL) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

secrets.o: $(MAIN_SRC) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$(PROG)
	@rm secrets.o

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)
