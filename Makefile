all:	run

run:	kad.cpp
	g++ -O3 -o run kad.cpp

.PHONY: all
