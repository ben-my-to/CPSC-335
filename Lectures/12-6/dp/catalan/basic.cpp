// This program uses the above formula to find the nth Catalan number --> O(2^n)

#include <iostream>

using namespace std;

long int catalanNumber(int n) {
	// assumes C(0) and C(1) = 1
	if (n <= 1) return 1;
	long int count = 0;
	for (int i = 1; i < n; i++) count += catalanNumber(i) * catalanNumber(n-i);
	return count;
}

int main() {
	for (int i = 1; i <= 11; i++)
		cout << "Number of BST with " << i-1 << " nodes = " << catalanNumber(i) << endl;

	return 0;
}

