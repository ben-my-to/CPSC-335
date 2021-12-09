#include <vector>

using namespace std;

void BubbleSort(vector<int> A) {
    bool dbit;
    for (int i = 0; i < A.size()-1; ++i) {
        dbit = false;
        for (int j = 0; j < A.size()-1-i; ++j) {
            if (A[j+1] < A[j]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                dbit = true;
            }
        }
        if (!dbit) break;
    }
}