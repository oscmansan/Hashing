#include "BloomFilter.h"

BloomFilter::BloomFilter(int numHashes, int numBits)
{
    bits = vector<bool>(numBits, false);
    this->numHashes = numHashes;
}

void BloomFilter::insert(int numberInput)
{
    //Calcular el hash numHashes vegades.
    //Per cada hash i calculat, marcar el bit que ens doni a true.
    for(int i = 0; i < numHashes; ++i)
    {
        int bit = hash(numberInput, i);
        bits[bit] = true;
    }
}

bool BloomFilter::contains(int numberInput)
{
    //Per cada hash resultant, mira si el bit es true
    //Si troba algun que sigui false, vol dir que numberInput
    // no ha estat insertat a aquest bloomFilter
    for(int i = 0; i < numHashes; ++i)
    {
        int bit = hash(numberInput, i);
        if(!bits[bit]) return false;
    }
    //Tots els bits els ha trobat a true
    //Es probable que numberInput estigui contingut
    return true;
}

int BloomFilter::hash(int numberInput, int hashi)
{
    return (numberInput * hashi) % bits.size(); //diferent hash per cada hashi
}
