all: bin/main.exe bin/genDictionary.exe bin/genText.exe

bin/main.exe: src/main.cpp obj/bloom.o obj/cuckoo.o obj/search.o
	g++ --std=c++11 src/main.cpp obj/bloom.o obj/cuckoo.o obj/search.o -o bin/main.exe

obj/bloom.o: src/BloomFilter.h src/BloomFilter.cpp
	g++ --std=c++11 -c src/BloomFilter.cpp -o obj/bloom.o
	
obj/cuckoo.o: src/CuckooHashing.h src/CuckooHashing.cpp
	g++ --std=c++11 -c src/CuckooHashing.cpp -o obj/cuckoo.o

obj/search.o: src/DichotomicSearch.h src/DichotomicSearch.cpp
	g++ --std=c++11 -c src/DichotomicSearch.cpp -o obj/search.o

bin/genDictionary.exe: src/genDictionary.cpp
	g++ -std=c++11 src/genDictionary.cpp -o bin/genDictionary.exe

bin/genText.exe: src/genText.cpp
	g++ -std=c++11 src/genText.cpp -o bin/genText.exe


clean:
	rm -rf obj/*.o bin/*.exe
