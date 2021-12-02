#include <iostream>
#include <algorithm>
#include <string.h>

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
	if (j > 0) quickSort(a, j + 1); //a[0],........a[j]
	if (i < n-1) quickSort(a + i, n - i); //a[i],........a[n-1]

}

template <class T>
void displayArray(T x[], int n) {
	for (int i = 0; i < n; ++i)
		cout << x[i] << "  ";
	cout << endl;
}

int compare(const void* a, const void* b) {
	return strcmp((char*)a , (char*)b); // compares two string pointed by a and b
	// < 0, the element pointed by a goes before element pointed by b (ascending order)
	// = 0, the element pointed by b is equivalent to element pointed by a
	// > 0, the element pointed by b goes after element pointed by a (descending order)
}

int main() {
	int b[8] = { 23, 398, 34, 100, 57, 67, 55, 320 };
	cout << "The original array a: "; displayArray(b, 8);
	quickSort(b, 8);
	cout << "The sorted array a: "; displayArray(b, 8);

	const int n = 5;
	int a[n] = { 9, 2, 8, 7, 1 };
	cout << "array a before sorting: "; displayArray(a, n);
	qsort(a, n, sizeof(int), compare);
	cout << "array a after sorting: "; displayArray(a, n);

	char s[4][10] = { "Tom", "Bob", "Mary", "Adam" };
	qsort(s, 4, sizeof(s[0]), compare);
	cout << "array s after sorting: "; displayArray(s, 4);

	float f[4] = { 1.2, 11.25, 7.678, 2.123 };
	qsort(f, 4, sizeof(float), compare);
	cout << "array f after sorting: "; displayArray(f, 4);

	char c[4] = { 'L', 'O', 'V', 'E' };
	qsort(c, 4, sizeof(char), compare);
	cout << "after c after sorting: "; displayArray(c, 4);

	return 0;
}
