#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

void usage()
{
    cout << "Usage: ./genDictionary.exe  numWords  minInt  maxInt" << endl;
    exit(-1);
}

int main(int argc, char* argv[])
{
    srand(time(0));
    unordered_set<int> numbers;

    if(argc < 4) usage();

    int n = atoi(argv[1]);
    int minInt = atoi(argv[2]);
    int maxInt = atoi(argv[3]);
    int range = (maxInt - minInt) + 1;

    if(minInt > maxInt) cout << "minInt must be less than maxInt" << endl;
    if(range < n) cout << "Very little range (" << (maxInt-minInt+1) <<
                                    ") to generate " << n << " words." << endl;

    while (numbers.size() < n) numbers.insert( (rand() % (range)) + minInt);
    for (int num : numbers) cout << num << endl;
}
