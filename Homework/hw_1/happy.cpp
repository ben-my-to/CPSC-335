#include <iostream>
#include <cmath>

using namespace std;

bool isHappy(int n) {
	int result = 0;

	while (result != 1 && result != 4) { // death-trap at 4
		result = 0;

		while (n) {
			int t = n % 10;
			cout << t << "^2 + ";
			result += pow(t, 2);
			n /= 10;
		}
		n = result;
		cout << "\b\b= " << result << endl;
	}

	return result == 1;
}

int main() {
	int input;

	cout << "Type a number: ";
	cin >> input;
	cout << endl;

	bool answer = isHappy(input);
	cout << endl << input << (answer ? " is a happy number\n" : " is not a happy number\n");
  
}
