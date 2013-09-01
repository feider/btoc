all: token.o main.cpp
	g++ -std=gnu++11 token.o main.cpp -o btoc

token.o: token.cpp
	g++ -c -std=gnu++11 token.cpp -o token.o