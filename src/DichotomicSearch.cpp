#include "DichotomicSearch.h"
#include <iostream>
using namespace std;
    
DichotomicSearch::DichotomicSearch() : Dictionary("DichotomicSearch") 
{
	sorted = true;
}

void DichotomicSearch::insert(int k) 
{
	sorted = false;
    elements.push_back(k);
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
	if (not sorted) 
	{
		quickSort(elements,0,elements.size());
		sorted = true;
	}
	
	return search(k, 0, elements.size());
}