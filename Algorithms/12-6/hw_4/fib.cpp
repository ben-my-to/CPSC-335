#include <iostream>

using namespace std;

size_t memo[100] = { 0 };

// int cassini(int n) { return (n & 1) ? -1 : 1; }

size_t fib(const int& n) {
	if (memo[n]) return memo[n];
	if (n <= 2) return memo[n] = 1;
	else {
		memo[n] = fib(n-1) + fib(n-2);
		return memo[n];
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "usage: ./<binary> <integer>\n";
		exit(1);
	}

	if (atoi(argv[1]) < 0) {
		cout << "instance must be >= 0\n";
		exit(1);
	}

	cout << fib(atoi(argv[1])) << endl;

	return 0;
}
