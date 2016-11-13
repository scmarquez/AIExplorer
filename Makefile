Explorer: main.o Explorer.o
	g++ -o Explorer main.o Explorer.o
main.o: main.cpp Explorer.h
	g++ -c -o main.o main.cpp
Explorer.o: Explorer.cpp Explorer.h
	g++ -c -o Explorer.o Explorer.cpp