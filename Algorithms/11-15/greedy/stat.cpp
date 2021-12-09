#include <iostream>
#include <algorithm>
#include <time.h>   // time
#include <stdlib.h> // srand, rand
#include <string.h> // memset
#include <stack>

using namespace std;

#define SIZE 15

void displayArray(int a[]) {
	for (int i = 0; i < SIZE; ++i) {
		if (a[i] != 0) cout << a[i] << " ";
	}
	cout << endl;
}

int median(int a[]) {
	if (SIZE % 2 == 0) {
		return (a[(SIZE+2)/2] + a[SIZE/2]) / 2;
	}
	return a[SIZE/2];
}

int mean(int a[]) {
	int total = 0;
	for (size_t i = 0; i < SIZE; ++i) total += a[i];
	return total / SIZE;
}

void mode(int a[]) {
	int freq[SIZE] = { 0 }, result[SIZE] = { 0 }, max = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (++freq[a[i]] > max) max = freq[a[i]];
	}

	for (int i = 0, k = 0; i < SIZE; ++i) {
		if (freq[i] == max) result[k++] = i;	
	}

	displayArray(result);
}

int main() {
	int *a = new int[SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 6 + 1; // generates random numbers between 1 and 6
	}

	cout << "Original Array: "; displayArray(a);
	sort(a, a + SIZE);
	cout << "Sorted Array: "; displayArray(a);
	cout << "Mean: " << mean(a) << endl;
	cout << "Median: " << median(a) << endl;
	cout << "Mode: "; mode(a);

	delete []a; // clean up after yourself
	return 0;
}
