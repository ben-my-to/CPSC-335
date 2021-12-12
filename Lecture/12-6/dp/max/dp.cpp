#include <iostream>

using namespace std;

int maxConSubsequence(int A[], int n) {
	int *M = new int[n]; M[n] = 0; // create M[n]
	int maxSum = 0;

	M[0] = (A[0] > 0) ? A[0] : 0;

	for (int i = 1; i < n; ++i) {
		M[i] = (M[i - 1] + A[i] > 0) ? M[i - 1] + A[i] : 0;
	}

	for (int i = 0; i < n; i++) {
		if (M[i] > maxSum) maxSum = M[i];
	}

	delete []M;
	return maxSum;
}

int main() {
	int a[6] = { -2, 11, -4, 13, -5, 2 }; cout <<  "Max subsequence in array a is = " << maxConSubsequence(a, 5) << endl;
	int b[6] = { 1, -3, 4, -2, -1, 6 }; cout << "Max subsequence in array b is = " <<  maxConSubsequence(b, 6) << endl;

	return 0;
}

