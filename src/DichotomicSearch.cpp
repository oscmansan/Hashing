#include "DichotomicSearch.h"
#include <iostream>
#include <algorithm>
using namespace std;
    
DichotomicSearch::DichotomicSearch() : Dictionary("DichotomicSearch"), compares(0) { }

void DichotomicSearch::insert(int k) 
{
    elements.push_back(k);
}

int DichotomicSearch::quickSortPartition (int l, int r)
{

    int p = l;
    int pivotElement = elements[l];
 
    for(int i = l+1 ; i <= r ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        ++compares;
        if(elements[i] <= pivotElement)
        {
            p++;
            swap(elements[i], elements[p]);
        }
    }
 
    swap(elements[p], elements[l]);
 
    return p;
}
 

void DichotomicSearch::quickSort(int l, int r)
{
    if (l < r)
    {
        int pivot_index = quickSortPartition(l, r); 
        quickSort(l, pivot_index - 1);
        quickSort(pivot_index + 1, r);
    }
}


bool DichotomicSearch::search(int k, int l, int r) 
{
	if (r < l) return false;

	int p = l + (r-l)/2;
    ++compares;
	if (elements[p] == k) return true;
	++compares;
    if (elements[p] <  k) return search(k, p+1, r);
	++compares;
    if (elements[p] >  k) return search(k, l, p-1);
}

bool DichotomicSearch::contains(int k) 
{
	return search(k, 0, elements.size());
}

void DichotomicSearch::onAllInserted() 
{
    quickSort(0, elements.size());
    //sort(elements.begin(), elements.end());
}

void DichotomicSearch::printExtras(void *extra) {
    cout <<  compares;
}
