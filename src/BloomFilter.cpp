#include "BloomFilter.h"

BloomFilter::BloomFilter(int n) : Dictionary("BloomFilter")
{
    m = n*8;
    bits = vector<bool>(m, false);
    positivesCount = 0;
}

void BloomFilter::insert(int x)
{
    bits[hash(x,0)] = bits[hash(x,1)] = true;
}

bool BloomFilter::contains(int x)
{
    //Bit a false, impossible que hi sigui
    if(!bits[hash(x,0)] || !bits[hash(x,1)]) return false;

    //Es probable que numberInput estigui contingut
    ++positivesCount;
    return true;
}

int BloomFilter::hash(int x, int i)
{
    return (x/(m*i+1)) % m;
}

void BloomFilter::printExtras(void *extra)
{
    int realPositivesCount = *((int*) extra);
    std::cout << "Tant per cent de falsos positius: " <<
                 (float(positivesCount-realPositivesCount)/positivesCount) * 100.0f
              << "%" << std::endl;
}
