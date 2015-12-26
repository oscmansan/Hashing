all: main randomGen

main: bloom.o
	g++ --std=c++11 main.cpp bloom.o -o main.exe

bloom.o: BloomFilter.h BloomFilter.cpp
	g++ --std=c++11 -c BloomFilter.cpp -o bloom.o

randomGen:
	g++ -std=c++11 randomGen.cpp -o randomGen.exe

clean:
	rm -rf *.exe *.o
