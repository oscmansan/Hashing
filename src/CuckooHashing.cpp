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
	while (not insert(k, 0)) {
		++i;
		vector<int> backupT1 = T1;
		vector<int> backupT2 = T2;
		T1 = vector<int>(m,-1);
		T2 = vector<int>(m,-1);

		bool valid_rehash = true;
		for (int x : backupT1) {
			if (x != -1) {
				if ( not insert(x,0)) {
					valid_rehash = false;
					break;
				}
			}
		}
		if (valid_rehash) {
			for (int x : backupT2) {
				if (x != -1) {
					if (not insert(x,0)) {
						valid_rehash = false;
						break;
					}
				}
			}
		}
	}
}

bool CuckooHashing::insert(int x, int n) {
	if (n < 100) {
		if(T1[hash(x,true)] == -1) {
			T1[hash(x,true)] = x;
		}
		else {
			int y = T1[hash(x,true)];
			T1[hash(x,true)] = x;
			if (T2[hash(y,false)] == -1) {
				T2[hash(y,false)] = y;
			}
			else {
				int z = T2[hash(y,false)];
				T2[hash(y,false)] = y;
				return insert(z,n+1);
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
	if (hash(k,true) == k) return true;
	else if (hash(k,false) == k) return true;
	else return false;
}

int CuckooHashing::hash(int k, bool t) {
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