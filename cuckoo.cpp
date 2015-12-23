#include <iostream>
#include <vector>
using namespace std;

class Cuckoo {
    
public:
    
    Cuckoo(int m) {
	this->m = m;
	
	T1 = vector<int>(m,-1);
	T2 = vector<int>(m,-1);
    }
    
    bool insert(int x, int n) {
	if (n < 100) {
	    if(T1[h1(x)] == -1) {
		T1[h1(x)] = x;
	    }
	    else {
		int y = T1[h1(x)];
		T1[h1(x)] = x;
		if (T2[h2(y)] == -1) {
		    T2[h2(y)] = y;
		}
		else {
		    int z = T2[h2(y)];
		    T2[h2(y)] = y;
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
    
    void printResult() {
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
    
private:
    
    int m;
    vector<int> T1;
    vector<int> T2;
    
    int h1(int k) {
	return k % m;
    }
    
    int h2(int k) {
	return (k/m) % m;
    }
};

int main() {
    int m;
    cin >> m;
    
    Cuckoo cuckoo(m);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	int k;
	cin >> k;
	if (!cuckoo.insert(k,0)) break;
    }
    
    cuckoo.printResult();
}