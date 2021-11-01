# Makefile for Project E, Lecture 2
# Writen with help of Petar Susac and Luka Jengic

# Common source and object codes
SRC=$(wildcard ./src/*.c)
OBJ=$(patsubst %.c,%.o,$(SRC))

# Source and object codes specific to one program
EXESRC=$(wildcard exesrc/*.c)
EXEOBJ=$(patsubst %.c,%.o,$(EXESRC))
EXE=$(patsubst exesrc/%.c,exe/%.elf,$(EXESRC))

# Compiler settings
CC=gcc
CFLAGS=-I inc/
LDFLAGS=-lm

.SECONDARY:

all: $(EXE)

exe/%.elf: exesrc/%.o $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXE) $(EXEOBJ)

run:
	for x in $(EXE); do ./$$x; done
