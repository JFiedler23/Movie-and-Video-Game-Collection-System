#Targets
CollectionSystem: main.o Game.o Movie.o Functions.o
	g++ main.o Game.o Movie.o Functions.o -o CollectionSystem

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Movie.o: Movie.cpp Movie.h
	g++ -c Movie.cpp

Functions.o: Functions.cpp Functions.h
	g++ -c Functions.cpp

clean:
	rm *.o CollectionSystem
