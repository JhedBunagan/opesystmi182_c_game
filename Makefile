# Makefile


CC = gcc      

LDLIBS=-lncurses -lconio -lwindows

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}


clean:
	@echo "Cleaning up..."
	rm -rvf *.o ${BINS}

