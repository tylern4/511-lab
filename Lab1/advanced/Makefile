CC = g++
CCFLAGS = $(shell root-config --cflags)
LINKS = $(shell root-config --libs)
PROG = $(patsubst %.cpp,%,$(wildcard *.cpp))

.PHONY: all clean

all: $(PROG)

$(PROG): %: %.cpp
	$(CC) -O3 $(CCFLAGS) -o $@ $< $(LINKS)

clean:
	rm -f $(PROG)
