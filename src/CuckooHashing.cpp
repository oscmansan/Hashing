#include "CuckooHashing.h"
#include <iostream>
using namespace std;
    
CuckooHashing::CuckooHashing(int m) : Dictionary("CuckooHashing") {
    this->m = m;
    this->i = 0;
    
    T1 = vector<int>(m,-1);
    T2 = vector<int>(m,-1);
}

void CuckooHashing::insert(int k) {
    while (not insert(k,i,0)) {
	++i;
	vector<int> backupT1 = T1;
	vector<int> backupT2 = T2;
	T1 = vector<int>(m,-1);
	T2 = vector<int>(m,-1);
	
	bool valid_rehash = true;
	for (int x : backupT1) {
	    if (not insert(x,i,0)) {
		valid_rehash = false;
		break;
	    }
	}
	if (valid_rehash) {
	    for (int x : backupT2) {
		if (not insert(x,i,0)) {
		    valid_rehash = false;
		    break;
		}
	    }
	}
    }
}

bool CuckooHashing::insert(int x, int i, int n) {
    if (n < 100) {
	if(T1[hash(x,i,true)] == -1) {
	    T1[hash(x,i,true)] = x;
	}
	else {
	    int y = T1[hash(x,i,true)];
	    T1[hash(x,i,true)] = x;
	    if (T2[hash(y,i,false)] == -1) {
		T2[hash(y,i,false)] = y;
	    }
	    else {
		int z = T2[hash(y,i,false)];
		T2[hash(y,i,false)] = y;
		return insert(z,i,n+1);
	    }
	}
	return true;
    }
    else {
	cout << "infinite loop when inserting " << x << endl;
	return false;
    }
}

bool CuckooHashing::contains(int k) {
    if (hash(k,i,true) == k) return true;
    else if (hash(k,i,false) == k) return true;
    else return false;
}

int CuckooHashing::hash(int k, int i, bool t) {
    if (t)
	return (k*(i+1)) % m;
    else
	return (k*(i+1)/m) % m;
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