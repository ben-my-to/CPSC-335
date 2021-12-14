#include <iostream>
#include <cmath>

using namespace std;

double cassini(int n) {
	if (n <= 1) return 1;
	return (pow(-1, n) + cassini(n-1) * cassini(n-1)) / cassini(n-2);
}

int main() {
	cout << "First Ten Fibonacci Sequence using Cassini's Identity: ";

	for (int n = 0; n < 10; n++) cout << cassini(n) << " ";
	cout << endl;
	return 0;
}
