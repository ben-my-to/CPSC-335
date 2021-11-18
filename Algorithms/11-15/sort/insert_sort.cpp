#include <iostream>
using namespace std;

void insertSort(int a[], int n) {
	int temp, j;

	for (int i = 1; i < n; ++i) {
		temp = a[i], j = i-1;
		while (a[j] > temp && j >= 0) a[j + 1] = a[j--];
		a[j+1] = temp;
	}
}

void displayArray(int a[], int n) {
	for (int i = 0; i < n; ++i)
		cout << a[i] << "  ";
	cout << endl;
}

int main() {
	int a[6] = { 3, 9, 7, 1, 8 ,5};
	cout << "This is the original array a: "; displayArray(a, 6);
	insertSort(a, 6);
	cout << "The sorted form of array a : "; displayArray(a, 6);

	return 0;
}
