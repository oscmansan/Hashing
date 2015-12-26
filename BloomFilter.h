#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <iostream>
#include <vector>

using namespace std;

class BloomFilter
{
private:

    vector<bool> bits;
    int numHashes;

    //Calcula el hash pel nombre numberInput,
    // utilitzant la funcio de hash numero hashi
    int hash(int numberInput, int hashi);

public:

    //input     = vector dels inputs
    //numHashes = nombre de hashes diferents a aplicar a cada input.
    //            Quant mes gran menys probabilitat de fals positiu.
    //numSlots  = quantitat de slots en el array de bits.
    //            Quant mes gran menys probabilitat de fals positiu.
    BloomFilter(int numHashes, int numBits);

    //Actualitza la taula de bits, fent hash amb numberInput
    void insert(int numberInput);

    //Diu si aquest BloomFilter conte numberInput
    bool contains(int numberInput);

};

#endif // BLOOMFILTER_H
