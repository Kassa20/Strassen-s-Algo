CC=g++

brute: brute.cpp
	$(CC) -g -o $@ $<

strassen: strassen.cpp
	$(CC) -g -o $@ $<

all: brute strassen

run_brute: brute
	./brute

run_strassen: strassen
	./strassen
