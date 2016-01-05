#ifndef DICHOTOMICSEARCH_H
#define DICHOTOMICSEARCH_H

#include <vector>
#include "Dictionary.h"

using namespace std;

class DichotomicSearch : public Dictionary
{
private:
    vector<int> elements;
    void quickSort(int l, int r);
    int  quickSortPartition(int l, int r);
    bool search(int  k, int l, int r);
    long long compares;

public:

    DichotomicSearch();

    //Insereix la clau k a la taula de hash
    void insert(int k);

    //Diu si la taula de hash conte la clau k
    bool contains(int k);

    void onAllInserted();

    void printExtras(void *extra);
};

#endif // DICHOTOMICSEARCH_H
