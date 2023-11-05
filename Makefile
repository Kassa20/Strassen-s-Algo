CC=g++

brute: brute.cpp
	$(CC) -g3 -o $@ $<

all: brute

run: brute
	./brute