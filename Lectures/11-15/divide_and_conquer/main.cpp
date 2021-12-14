#include <iostream>
#include <algorithm>

using namespace std;

size_t GCD (size_t m, size_t n) {
	if (n == 0) return m;
	else {
		cout << "GCD of " << m << " mod " << n << " = " << m%n << endl;
		return GCD(n, m % n);
	}
}

int binarySearch(int a[], int first, int last, int X) {
	if (first > last) return -1;
	else {
		int mid = (first+last) / 2;
		if (X == a[mid]) return mid;
		else if (X < a[mid]) return binarySearch(a, first, mid-1, X);
		else return binarySearch(a, mid+1, last, X);
	}
}

int power(int n, int k) {
	if (k == 0)			 return 1;
	else if (k % 2 != 0) return n * power(n, k-1); // remove a power = k-1
	else				 return power(n, k/2) * power(n, k/2); // base is odd
}

int main() {
	int a = 2, b = 5;
	int arr[6] = {0, 1, 2, 3, 4, 10};
	cout << "Key found at index: " << binarySearch(arr, 0, 5, 10) << endl;
	cout << a << "^" << b << " = " << power(a, b) << endl;
	
	cout << GCD(32670, 2475) << endl;

	return 0;
}

