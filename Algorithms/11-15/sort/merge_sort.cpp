#include <iostream>

using namespace std;

void Merge(int A[], int p, int q, int r) {
	int n1 = q-p+1, i, j, k;
    int n2 = r-q;
	int *L = new int[n1], *R = new int[n2];                       

	for (i = 0; i < n1; i++) L[i] = A[p+i];
	for (j = 0; j < n2; j++) R[j] = A[q+j+1];

	i = 0, j = 0;
	for (k = p; i < n1 && j < n2; k++) {
		if (L[i] < R[j]) { A[k] = L[i++]; }
		else { A[k] = R[j++]; }
	}
    // if L[] has more elements than R[] then it will put all the remaining elements of L[] into A[]
	while (i < n1) A[k++] = L[i++];
    // if R[] has more elements than L[] then it will put all the remaining elements of R[] into A[]
	while (j < n2) A[k++] = R[j++];
}

void MergeSort(int A[], int p, int r) {
	int q;
	if (p < r) {
        q = (p + r) / 2; // q is the middle element to divide the array
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int main() {
	int A_Size;
	int *A;
	cout << "Enter number of elements: ";
	cin >> A_Size;
	A = new int[A_Size];
	cout << "Enter the array elements: ";
	for (int i = 0; i < A_Size; i++) {
		cin >> A[i];
	}
	MergeSort(A, 0, A_Size - 1);
	cout << "Sorted form of the array A: ";
	for (int i = 0; i < A_Size; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
