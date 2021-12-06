#include <iostream>

using namespace std;

int maxConSubsequence(int A[], int n) {
	int maxSum = 0, fromIndex = 0, toIndex = 0;
	for (int i = 0; i < n; i++) {
		int currentSum = 0;
		for (int j = i; j < n; j++) {
			currentSum += A[j];
			if (currentSum > maxSum) {
				maxSum = currentSum;
				fromIndex = i; toIndex = j;
			}
		}
	}
	for (int r = fromIndex; r <= toIndex; ++r) cout << A[r] << " ";
	return maxSum;
}

int main() {
	int a[6] = { -2, 11, -4, 13, -5, 2 };
	cout << "--> " << maxConSubsequence(a, 5) << endl;

	int b[6] = { 1, -3, 4, -2, -1, 6 };
	cout << "--> " << maxConSubsequence(b, 6) << endl;
	return 0;
}
