// dp --> O(n^2)

#include <iostream>

using namespace std;

long int catalanDP(int n) {
	// table to store previous values of Ci
	int *table = new int[n+1];
	table[0] = table[1] = 1;
	// fill in enteries in table[] using recursive formula
	for (int i = 2; i <= n; i++) {
		table[i] = 0;
		for (int j = 0; j < i; j++)
			table[i] += table[j] * table[i-j-1];
	}

	delete []table;
	return table[n];
}

int main() {
	for (int i = 0; i < 11; i++)
		cout << "The " << i+1 << " the catalan number is " << catalanDP(i) << endl;

	return 0;
}
