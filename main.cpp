#include <iostream>
#include <istream>
#include <fstream>
#include <vector>

#include "BloomFilter.h"

using namespace std;

void usage();
void bloomFilter();

vector<int> dictWords; //Contindra les paraules del diccionari
vector<int> textWords; //Contindra les paraules del text

int main(int argc, char **argv)
{
    if(argc < 3) usage();

    // Llegir input ////////////////////////////////////
    int n;
    ifstream inDict(argv[1]); //Llegir paraules diccionari
    while (inDict >> n) dictWords.push_back(n);
    ifstream inText(argv[2]); //Llegir paraules text fins eof
    while (inText >> n) textWords.push_back(n);
    /////////////////////////////////////////////////////

    //BloomFilter
    bloomFilter();

    return 0;
}


void bloomFilter()
{
    const int BFNumBits   = 500000;
    const int BFNumHashes = 2;

    BloomFilter bf(BFNumHashes, BFNumBits);
    for(int tw : textWords) bf.insert(tw);

    // Resultats ///////////////////////////////////////
    cout << "Resultats BloomFilter:" << endl;
    for(int dw : dictWords)
    {
        if (bf.contains(dw))
            cout << "El text conte la paraula '" << dw << "'" << endl;
        else
            cout << "El text NO conte la paraula '" << dw << "'" << endl;
    }
    cout << "___________________" << endl;
}

void usage()
{
    cout << "Usage: ./main.exe dictFile.in textFile.in";
    exit(-1);
}
