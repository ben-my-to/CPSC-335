#include <iostream>
using namespace std;

void sift(int a[], int k, int n) {
	int i, j, x;
	i = k; x = a[i];
	while ((j = 2*i + 1) < n) {
		if (j < n - 1 && a[j] < a[j + 1]) j++;
		if (x >= a[j]) break;
		a[i] = a[j]; i = j;
	}
	a[i] = x;
}

void heapSort(int a[], int n) {
	int x;
	for (int k = n / 2 - 1; k >= 0; k--) {
        sift(a, k, n);
    }
	while (--n > 0) {
		x = a[0];
        a[0] = a[n];
        a[n] = x;
		sift(a, 0, n);
	}
}
void displayArray(int a[], int n) {
	for (int i = 0; i < n; ++i)
		cout << a[i] << "  ";
	cout << endl;
}

int main() {
	int a[6] = { 80, 50, 70, 30, 40, 25 };
	cout << "This is the original array a: "; displayArray(a, 6);
	heapSort(a, 6);
	cout << "The sorted form of array a: "; displayArray(a, 6);
	return 0;
}
