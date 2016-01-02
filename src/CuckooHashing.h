#ifndef CUCKOOHASHING_H
#define CUCKOOHASHING_H

#include <vector>
#include "Dictionary.h"

using namespace std;

class CuckooHashing : public Dictionary
{
private:

    int m, i;
    vector<int> T1;
    vector<int> T2;
    vector<int> data;

    int hash(int k, bool t);
    bool insert(int x, int n);

public:

    //m: tamany de les taules de hash
    CuckooHashing(int m);

    //Insereix la clau k a la taula de hash
    void insert(int k);

    //Diu si la taula de hash conte la clau k
    bool contains(int k);
    
    void printResult();
};

#endif // CUCKOOHASHING_H
