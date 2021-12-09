#include <iostream>
#include <vector>

using namespace std;

int StringMatch(vector<char>& T, vector<char>& P) {
    int n = T.size();
    int m = P.size();


    for (int i = 0; i < n-m; ++i) {
        int j = 0;
        while (j < m && P[j] == T[i + j]) {
            j += 1;
        }
        if (j == m) return i;
    }
    return -1;
}