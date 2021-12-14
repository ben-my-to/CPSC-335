#include <vector>

using namespace std;

void SelectionSort(vector<int> A) {
    int min;

    for (int i = 0; i < A.size()-1; ++i) {
        min = i;
        for (int j = i + 1; j < A.size(); ++j) {
            if (A[j] < A[min]) min = j;
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}