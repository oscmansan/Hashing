#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <chrono>

#include "Dictionary.h"
#include "BloomFilter.h"
#include "CuckooHashing.h"
#include "DichotomicSearch.h"

using namespace std;
using namespace std::chrono;

void usage();
void bloomFilter();

vector<int> dictWords; //Contindra les paraules del diccionari
vector<int> textWords; //Contindra les paraules del text


int main(int argc, char **argv)
{
    if(argc < 3) usage();

    // LLEGIR INPUT /////////////////////////////////////
    int n;
    ifstream inDict(argv[1]); //Llegir paraules diccionari
    while (inDict >> n) dictWords.push_back(n);
    ifstream inText(argv[2]); //Llegir paraules text fins eof
    while (inText >> n) textWords.push_back(n);
    /////////////////////////////////////////////////////

    // CREAR DICCIONARIS ////////////////////////////////
    const int BFNumBits    = 5000;
    const int BFNumVectors = 2;
    const int BFNumHashes  = 2;

    vector<Dictionary*> dics;
    
    dics.push_back(new DichotomicSearch());
    
    dics.push_back(new CuckooHashing(dictWords.size()));
    
    dics.push_back(new BloomFilter(BFNumHashes, BFNumVectors, BFNumBits));
    /////////////////////////////////////////////////////


    // EXPERIMENTS //////////////////////////////////////
    clock_t start = clock();
    double seconds = 0;

    for(Dictionary *d : dics)
    {
        start = clock();

        for(int dw : dictWords) d->insert(dw);
        cout << "Resultats " << d->name << ":" << endl;
        for(int tw : textWords)
        {
            if (d->contains(tw)) cout << "=====>  El text conte la paraula '" << tw << "'" << endl;
            else cout << "El text NO conte la paraula '" << tw << "'" << endl;
        }
        cout << "___________________" << endl;

        seconds = double(clock() - start) / CLOCKS_PER_SEC;
        cout << "Temps que triga el " << d->name << ": " << seconds << " segons." << endl << endl << endl; //Print time
    }
    /////////////////////////////////////////////////////

    return 0;
}


void usage()
{
    cout << "Usage: ./main.exe dictFile.in textFile.in" << endl;
    exit(-1);
}
