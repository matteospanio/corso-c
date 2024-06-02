CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Wextra
PROG = palindromi
SRC = palindromi.c

ifeq ($(DEBUG),1)
	CFLAGS += -DDEBUG -g
endif

all: $(PROG)

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@
	@./$(PROG)

.PHONY: clean
clean:
	rm -f $(PROG)
