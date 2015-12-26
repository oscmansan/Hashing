#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

void usage()
{
    cout << "Usage: ./randomGen.exe    numberAmount    greatestNumber" << endl;
    exit(-1);
}

int main(int argc, char* argv[])
{
    srand(time(0));
    unordered_set<int> numbers;

    if(argc < 3) usage();

    int n = atoi(argv[1]);
    int max = atoi(argv[2]);
    while (numbers.size() < n) numbers.insert(rand() % max);
    for (int num : numbers) cout << num << endl;
    cout << endl;
}
