#include <iostream>
#include <vector>

using namespace std;

int SeqSearch(size_t arr[], size_t K) {
    size_t i, n = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < n && arr[i] != K; ++i);
    return (i < n) ? i : -1;
}

int SeqSearchImprove(vector<int> A, int K) {
    A.push_back(K);
    int i = 0;

    while (A[i++] != K);
    return (i < A.size()) ? i : -1;
}

size_t MaxElement(size_t arr[]) {
    size_t maxval = arr[0], n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxval) maxval = arr[i];
    }

    return maxval;