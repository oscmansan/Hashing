#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

void usage()
{
    cout << "Usage: ./genText.exe  numWords  minInt  maxInt" << endl;
    exit(-1);
}

int main(int argc, char* argv[])
{
    srand(time(0));
    if(argc < 4) usage();

    int n = atoi(argv[1]);
    int minInt = atoi(argv[2]);
    int maxInt = atoi(argv[3]);

    for(int i = 0; i < n; ++i)
    {
        cout << (rand() % (maxInt-minInt)) + minInt + 1 << " ";
    }
}
