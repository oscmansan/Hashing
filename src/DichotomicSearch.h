#ifndef DICHOTOMICSEARCH_H
#define DICHOTOMICSEARCH_H

#include <vector>
#include "Dictionary.h"

using namespace std;

class DichotomicSearch : public Dictionary
{
private:
    vector<int> elements;
    void quickSort(vector<int> &arr, int l, int r);
    int  quickSortPartition(vector<int> &arr, int l, int r);
    bool search(int  k, int l, int r);

public:

    DichotomicSearch();

    //Insereix la clau k a la taula de hash
    void insert(int k);

    //Diu si la taula de hash conte la clau k
    bool contains(int k);

    void onAllInserted();
};

#endif // DICHOTOMICSEARCH_H
