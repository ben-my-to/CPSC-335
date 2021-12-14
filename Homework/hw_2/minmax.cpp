#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int min;
    int max;

    void print() const { cout << "Max: " << max << "\n" << "Min: " << min << "\n\n"; }
};

node minmax(int a[], int s, int n) {
    if (n-s > 2) { // array size contains at least 2 items
        node b = minmax(a, s, (n + s)/2); b.print();
        node c = minmax(a, (n + s)/2, n); c.print();
        return { min(b.min, c.min), max(b.max, c.max) };
    }
    return { min(a[s], a[n-1]), max(a[s], a[n-1]) };
}

int main() {
    int a[8] = { 20, 5, 7, 25, 30, 1, 9, 12 };
    node result = minmax(a, 0, 8);
    result.print();
    return 0;
}
