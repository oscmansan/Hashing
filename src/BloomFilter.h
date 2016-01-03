#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <iostream>
#include "Dictionary.h"

using namespace std;

class BloomFilter : public Dictionary
{
private:

    vector< vector<bool> > bits;
    int numHashes, numVectors;
    int positivesCount;

    //Calcula el hash pel nombre numberInput,
    // utilitzant la funcio de hash numero hashi
    int hash(int numberInput, int hashi, int vectori);

public:

    //input     = vector dels inputs
    //numHashes  = nombre de hashes diferents a aplicar a cada input.
    //numVectors = nombre de vectors de bits.
    //             Quant mes gran menys probabilitat de fals positiu.
    //numBits    = quantitat de bits en cada vector de bits.
    //             Quant mes gran menys probabilitat de fals positiu.
    //             (tenint en compte el hash usat)
    BloomFilter(int numHashes, int numVectors, int numBits);

    //Actualitza la taula de bits, fent hash amb numberInput
    void insert(int numberInput);

    //Diu si aquest BloomFilter conte numberInput
    bool contains(int numberInput);

    void printExtras(void *extra);
};

#endif // BLOOMFILTER_H
