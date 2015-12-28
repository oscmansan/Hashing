all: main.exe genDictionary.exe genText.exe

main.exe: bloom.o
	g++ --std=c++11 main.cpp bloom.o -o main.exe

bloom.o: BloomFilter.h BloomFilter.cpp
	g++ --std=c++11 -c BloomFilter.cpp -o bloom.o

genDictionary.exe: genDictionary.cpp
	g++ -std=c++11 genDictionary.cpp -o genDictionary.exe

genText.exe: genText.cpp
	g++ -std=c++11 genText.cpp -o genText.exe


clean:
	rm -rf *.exe *.o
