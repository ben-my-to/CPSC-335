#include <iostream>
#include <vector>

using namespace std;

const vector<vector<size_t>> A = {{0, 1}, {1, 1}};
vector<vector<size_t>> B = {{0, 1}, {1, 1}}, temp = {{0, 0}, {0, 0}};

void print(const vector<vector<size_t>> n) {
	cout << "{ ";
	for (vector<size_t> a : n) {
		for (size_t b : a) {
			cout << b << " ";
		}
	}
	cout << "}\n";
}

void f(size_t n) {
	if (n > 1) cout << "1" << endl;

	int c = 1;
	while (c++ < n) {
		// print
		cout << B[1][1] << " ";
		print(B);

		for (size_t i = 0; i < A.size(); i++) {
			for (size_t j = 0; j < B.size(); j++) {
				for (size_t k = 0; k < A.size(); k++) {
					temp[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		// copy
		for (int i = 0; i < B.size(); ++i) {
			for (int j = 0; j < B[i].size(); ++j) {
				B[i][j] = temp[i][j];
				temp[i][j] = 0;
			}
		}
	}
}

int main() {
	size_t input;

	cout << "Type a number: ";
	cin >> input;
	cout << endl;

	f(input);

	return 0;
}
