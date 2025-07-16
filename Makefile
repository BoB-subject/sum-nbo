sum-nbo.o: sum-nbo.cpp
	g++ -c sum-nbo.cpp

sum-nbo: sum-nbo.o
	g++ -o sum-nbo sum-nbo.o
