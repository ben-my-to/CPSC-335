#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1]; // K[n+1][W+1]

    // build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0) K[i][w] = 0;
			else if (wt[i-1] <= w) K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
			else K[i][w] = K[i - 1][w];
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int w = 0; w <= W; w++) cout << setw(5) << K[i][w];
		cout << endl;
	}
	return K[n][W];
}

int main() {
    // number of items and capacity of the knapsack
    int n = 5, W = 15;
	int val[5] = { 7, 9, 5, 12, 14 }, wt[5] = { 3, 4, 2, 6, 7 };
	
    int maxValue = knapSack(W, wt, val, n);
	cout << "\nMaximum value in the Knapsack = " << maxValue << endl;

    return 0;
}