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

//10.000 -> 50.000.000 en 10 intervals

int main(int argc, char **argv)
{
    if(argc < 3) usage();

    // LLEGIR INPUT /////////////////////////////////////
    int n;
    ifstream inDict(argv[1]); //Llegir paraules diccionari
    while (inDict >> n) dictWords.push_back(n);
    ifstream inText(argv[2]); //Llegir paraules text fins eof
    while (inText >> n) textWords.push_back(n);

    /*cout << "Tamany entrada" << endl;
    cout << dictWords.size() << endl;
    cout << textWords.size() << endl << endl;*/
    /////////////////////////////////////////////////////

    // CREAR DICCIONARIS ////////////////////////////////
    vector<Dictionary*> dics;
    dics.push_back( new DichotomicSearch() );
    dics.push_back( new CuckooHashing(dictWords.size()) );
    dics.push_back( new BloomFilter(dictWords.size())   );
    /////////////////////////////////////////////////////


    // EXPERIMENTS //////////////////////////////////////
    clock_t start = clock();
    double seconds = 0;
    int realCount = 0;
    bool f = true;

    //cout << "Algorisme\tTemps insercio\tTemps comprovacio" << endl;

    for(Dictionary *d : dics)
    {
        start = clock();

        for(int dw : dictWords) d->insert(dw);
        d->onAllInserted();

        seconds = double(clock() - start) / CLOCKS_PER_SEC;
        cout <<  d->name << "\t" << seconds ;
        //cout << endl << endl << endl;

        start = clock();

        //cout << "Resultats: " << d->name << ":" << endl;

        int count = 0;
        for(int tw : textWords)
        {
            if (d->contains(tw))
            {
                if(f) ++realCount;
                ++count;
            }
            // if (d->contains(tw)) cout << "=====>  El diccionari conte la paraula '" << tw << "'" << endl;
            // else cout << "El diccionari NO conte la paraula '" << tw << "'" << endl;
        }
        //cout << "___________________" << endl;

        seconds = double(clock() - start) / CLOCKS_PER_SEC;
        cout << "\t" << seconds << "\t";
        //cout << endl << endl << endl;
	
        d->printExtras(&realCount);
        cout << endl;
        f = false;
    }
    /////////////////////////////////////////////////////

    return 0;
}


void usage()
{
    cout << "Usage: ./main.exe dictFile.in textFile.in" << endl;
    exit(-1);
}
