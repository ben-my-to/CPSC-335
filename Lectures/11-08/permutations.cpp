#include <iostream>
#include <algorithm> // sort() and next_permutation()

/* NOTE: next_permutation() finds the next permutation of a given group of items */

using namespace std;

int numberOfPermutations(int n) {
	int it = 1; // compute n!
	for (int i = 2; i <= n; ++i) it *= i;
	return it;
}

void displayPermuatations(char x[], int n) {
	sort(x, x + n); // sorts array 'x'
	cout << numberOfPermutations(n) << " Permuations are \n";

	do {
		for (int i = 0; i < n; ++i) cout << x[i] << "  ";
		cout << endl;
	} while (next_permutation(x, x + n));
}

int main() {
	int n;
	cout << "Enter the set cardinality: ";
	cin >> n;
	// create a dynamic array of size n
	char *a = new char[n];
	// fill in the array
	for (int i = 0; i < n; ++i) {
		cout << "Enter a set element: ";
		cin >> a[i];
	}

	displayPermuatations(a, n);
	return 0;
}
