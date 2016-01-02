#include "DichotomicSearch.h"
#include <iostream>

using namespace std;
    
DichotomicSearch::DichotomicSearch() : Dictionary("DichotomicSearch") 
{
}

void DichotomicSearch::insert(int k) 
{
    elements.push_back(k); cout << "insert " << k << endl;
}

int DichotomicSearch::quickSortPartition (vector<int> &arr, int l, int r)
{
    int x = arr[r]; 
    int i = (l - 1); 
 
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]); 
        }
    }

    swap(arr[i + 1], arr[r]);
    return (i + 1);
}
 

void DichotomicSearch::quickSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int pivot_index = quickSortPartition(arr, l, r); 
        quickSort(arr, l, pivot_index - 1);
        quickSort(arr, pivot_index + 1, r);
    }
}


bool DichotomicSearch::search(int k, int l, int r) 
{
	if (r < l) return false;

	int p = l + (r-l)/2;
	if (elements[p] == k) return true;
	if (elements[p] <  k) return search(k, p+1, r);
	if (elements[p] >  k) return search(k, l, p-1);
}

bool DichotomicSearch::contains(int k) 
{
	return search(k, 0, elements.size());
}

void DichotomicSearch::onAllInserted()
{
    for(int i = 0; i < elements.size(); ++i) cout << elements[i] << ", "; cout << endl;
    quickSort(elements,0,elements.size());
    for(int i = 0; i < elements.size(); ++i) cout << elements[i] << ", "; cout << endl;
}
