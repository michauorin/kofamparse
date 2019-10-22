CFLAGS += -g -O3 -Wall -Wextra -pedantic
CXXFLAGS=$(CFLAGS) -std=c++17

all: kofamparse

clean:
	rm -f *.o kofamparse
