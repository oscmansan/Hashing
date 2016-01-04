#include "BloomFilter.h"

BloomFilter::BloomFilter(int dictCount) : Dictionary("BloomFilter")
{
    int m = dictCount * 4;
    bits = vector<bool>(m, false);
    positivesCount = 0;
}

void BloomFilter::insert(int numberInput)
{
    bits[hash(numberInput)] = true;
}

bool BloomFilter::contains(int numberInput)
{
    //Bit a false, impossible que hi sigui
    if(!bits[hash(numberInput)]) return false;

    //Es probable que numberInput estigui contingut
    ++positivesCount;
    return true;
}

int BloomFilter::hash(int numberInput)
{
    return numberInput % bits.size();
}

void BloomFilter::printExtras(void *extra)
{
    int realPositivesCount = *((int*) extra);
    std::cout << "Tant percent de falsos positius: " << (float(positivesCount)/realPositivesCount - 1.0f)*100.0f << "%" << std::endl;
}
