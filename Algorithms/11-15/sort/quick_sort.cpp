#include <iostream>

using namespace std;

void displayArray(int x[], int n) {
	for (int i = 0; i < n; ++i)
		cout << x[i] << " ";
	cout << endl;
}

void quickSort(int a[], int n) {
	int i = 0, j = n-1;
	int x = a[j/2], w;

	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i < j) {
			w = a[i]; a[i] = a[j], a[j] = w;		
		}
		else {
			if (i == j) { i++; j--; } break;
		}
	} while (++i <= --j);
	if (j>0) quickSort(a, j + 1);           //a[0],........a[j]
	if (i < n - 1) quickSort(a + i, n - i); //a[i],........a[n-1]

}

int main() {
	int a[8] = { 23, 398, 34, 100, 57, 67, 55, 320 };
	cout << "The original array a: "; displayArray(a, 8);
	quickSort(a, 8);
	cout << "The sorted array a: "; displayArray(a, 8);
	return 0;
}