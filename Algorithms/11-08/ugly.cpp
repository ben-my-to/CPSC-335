#include <iostream>

using namespace std;

bool isUgly(int n) {
	while (n % 2 == 0) n /= 2;
	while (n % 3 == 0) n /= 3;
	while (n % 5 == 0) n /= 5;

	return n == 1;	
}

int main() {
	int input;

	cout << "Type a number: ";
	cin >> input;

	cout << endl << input << (isUgly(input) ? " is an ugly number" : " is not an ugly number") << endl;

	return 0;
}
