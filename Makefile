all: token.o parser.o main.cpp backend.o
	g++ -std=gnu++11 backend.o parser.o token.o main.cpp -o btoc

token.o: token.cpp
	g++ -c -std=gnu++11 token.cpp -o token.o

parser.o: parser.cpp
	g++ -c -std=gnu++11 parser.cpp -o parser.o

backend.o: backend.cpp
	g++ -c -std=gnu++11 backend.cpp -o backend.o