#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <cmath>
#include <vector>
#include <iostream>
#include "Dictionary.h"

using namespace std;

class BloomFilter : public Dictionary
{
private:

    vector<bool> bits;
    int positivesCount, m;

    //Calcula el hash pel nombre numberInput,
    // utilitzant la funcio de hash numero hashi
    int hash(int x,int i);

public:

    BloomFilter(int dictCount);

    //Actualitza la taula de bits, fent hash amb numberInput
    void insert(int numberInput);

    //Diu si aquest BloomFilter conte numberInput
    bool contains(int numberInput);

    void printExtras(void *extra);
};

#endif // BLOOMFILTER_H
