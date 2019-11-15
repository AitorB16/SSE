CC=gcc
CFLAGS = -Wall -ggdb

ODIR=obj

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.h)

LDFLAGS = 
LIBS = -lm

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS)

sim: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o sim

