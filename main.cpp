#include <iostream>
#include <vector>

#include "BloomFilter.h"

using namespace std;

int main()
{
    const int BFNumBits   = 50000;
    const int BFNumHashes = 5;

    // Llegir input ////////////////////////////////////
    int n;
    vector<int> input;
    int greatestInput = 0;
    while (cin >> n)
    {
        greatestInput = max(n, greatestInput);
        input.push_back(n);
    }
    ////////////////////////////////////////////////////

    // Crear estructures ///////////////////////////////
    BloomFilter bf(BFNumHashes, BFNumBits);
    ////////////////////////////////////////////////////

    // Processar dades /////////////////////////////////
    for(int n : input)
    {
        bf.insert(n);
    }
    ////////////////////////////////////////////////////

    // Resultats ///////////////////////////////////////
    // BloomFilter
    cout << "Nombres que segons el BloomFilter hi son:" << endl;
    for(int i = 0; i < greatestInput; ++i)
    {
        if (bf.contains(i)) cout << i << endl;
    }
    cout << "___________________" << endl;
    ////////////////////////////////////////////////////

    return 0;
}
