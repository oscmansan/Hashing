#include "CuckooHashing.h"
#include <iostream>
#include <cmath>

using namespace std;

CuckooHashing::CuckooHashing(int M) : Dictionary("CuckooHashing") {
    this->m = 4*M; //log10(M)*M;
    this->i = 0;
    this->bounces = 0;

    T1 = vector<int>(m,-1);
    T2 = vector<int>(m,-1);
    srand(0);
}

void CuckooHashing::insert(int k) 
{
    data.push_back(k);
    bool b = insert(k,0);
    while (not b)
    {
        i = rand()%m;
        cout << i << endl;
		T1 = vector<int>(m,-1);
		T2 = vector<int>(m,-1);

        bool valid_rehash = true;
        for (int x : data) {
            if (not insert(x,0)) {
                valid_rehash = false;
                 break;
            }
        }
        b = valid_rehash;
    }
}

bool CuckooHashing::insert(int xx, int n)
{
    int x = xx;
    int initialBounces = bounces;
    while(bounces - initialBounces < 100000)
    {
        int h1 = hash(x, true);
        if(T1[h1] == -1)
        {
            T1[h1] = x;
            return true;
        }
        else
        {
            int last1 = T1[h1];
            T1[h1] = x; //replace
            ++bounces;

            int h2 = hash(last1, false);
            cout << h1 << ", " << h2 << endl;
            if (T2[h2] == -1)
            {
                T2[h2] = last1;
                return true;
            }
            else
            {
                ++bounces;
                x = T2[h2];
                T2[h2] = last1;
            }
        }
    }
    return false;
}

bool CuckooHashing::contains(int k) {
	if (T1[hash(k,true)] == k) return true;
	else if (T2[hash(k,false)] == k) return true;
	else return false;
}

int CuckooHashing::hash(int k, bool t) {
	if (t)
		return (k*(i+1)) % m;
    else
        return (int((sin(k*i)*0.5+0.5)*m) + i) % m;
}

void CuckooHashing::printResult() {
	cout << endl;

	cout << "+---------------+" << endl;
	cout << "|      T1       |" << endl;
	cout << "+-------+-------+" << endl;
	for (int i = 0; i < m; ++i) {
		if (T1[i] != -1)
			cout << "| " << i << "\t| " << T1[i] << "\t|" << endl;
	}
	cout << "+-------+-------+" << endl;

	cout << endl;

	cout << "+---------------+" << endl;
	cout << "|      T2       |" << endl;
	cout << "+-------+-------+" << endl;
	for (int i = 0; i < m; ++i) {
		if (T2[i] != -1)
			cout << "| " << i << "\t| " << T2[i] << "\t|" << endl;
	}
	cout << "+-------+-------+" << endl;
}

void CuckooHashing::printExtras(void *extra) {
	cout <<  bounces << "\t" << i;
}
