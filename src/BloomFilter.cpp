#include "BloomFilter.h"

BloomFilter::BloomFilter(int numHashes, int numVectors, int numBits) : Dictionary("BloomFilter")
{
    bits = vector< vector<bool> >(numVectors, vector<bool>(numBits, false));
    this->numHashes = numHashes;
    positivesCount = 0;
}

void BloomFilter::insert(int numberInput)
{
    //Per cada vector de bits...
    //Calcular el hash numHashes vegades.
    //Per cada hash i calculat, marcar el bit de l'index que ens doni a true.

    for(int i = 0; i < bits.size(); ++i)
    {
        for(int j = 0; j < numHashes; ++j)
        {
            int bit = hash(numberInput, j, i);
            bits[i][bit] = true;
        }
    }
}

bool BloomFilter::contains(int numberInput)
{
    //Per cada vector de bits...
    //Per cada hash resultant, mira si el bit es true
    //Si troba algun que sigui false, vol dir que numberInput
    // no ha estat insertat a aquest bloomFilter
    for(int i = 0; i < bits.size(); ++i)
    {
        for(int j = 0; j < numHashes; ++j)
        {

            int bit = hash(numberInput, j, i);

            //Un bit a false, impossible que hi sigui
            if(!bits[i][bit]) return false;
        }
    }

    ++positivesCount;

    //Tots els bits de tots els hashes de tots els vectors
    //els ha trobat a true
    //Es probable que numberInput estigui contingut
    return true;
}

int BloomFilter::hash(int numberInput, int hashi, int vectori)
{
    //Per cada combinacio (hashi, vectori) el hash resultant es diferent
    return (numberInput * (hashi+1) * (vectori+1)) % bits[0].size();
}

void BloomFilter::printExtras(void *extra)
{
    int realPositivesCount = *((int*) extra);
    std::cout << "Tant percent de encert: " << (float(realPositivesCount)/positivesCount)<< std::endl;
}
