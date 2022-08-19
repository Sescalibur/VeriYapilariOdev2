all: compile run

compile:
	g++ -I ./include/ -o ./lib/ArrayList.o -c ./src/ArrayList.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Ekle.o -c ./src/Ekle.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./bin/test ./lib/ArrayList.o ./lib/Node.o ./lib/Ekle.o ./lib/Radix.o ./lib/Queue.o ./src/test.cpp
	
run:
	./bin/test