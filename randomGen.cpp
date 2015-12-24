#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    srand(time(NULL));
    
    int n = atoi(argv[1]);
    
    unordered_set<int> numbers;
    
    while (numbers.size() < n) {
	numbers.insert(rand()%1000);
    }
    
    for (int num : numbers) {
	cout << num << " ";
    }
    
    cout << endl;
}