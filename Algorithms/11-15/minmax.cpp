#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

#define test(X) cout << "Max: " << X.max << endl << "Min: " << X.min << endl << endl;

using namespace std;

struct node { int min; int max; };

node minmax(int a[], int s, int n) {
    if (n-s > 2) {
        node b = minmax(a, s, (n + s)/2);
        test(b);
        node c = minmax(a, (n + s)/2, n);
        test(c);
        return { min(b.min, c.min), max(b.max, c.max) };
    }
    return { min(a[s], a[s+1]), max(a[s], a[s+1]) };
}

int main() {
    int a[8] = { 20, 5, 7, 25, 30, 1, 9, 12 };
    node result = minmax(a, 0, 8);
    cout << "Max: " << result.max << endl << "Min: " << result.min << endl;
    return 0;
}