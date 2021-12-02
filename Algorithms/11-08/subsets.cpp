#include <iostream>

using namespace std;

int main() {
    char A[3] = {'a', 'b', 'c'};

	// number of subsets = 8
    for (int i = 0; i < 8; ++i) {
        cout << "{";
        // 3 is the number of elements
        for (int j = 0; j < 3; ++j) {
			// 1 << j sets the bit position w/ respect to j
            if ((i & (1 << j)) > 0)
                cout << " " <<  A[j] << " ";
        }
        cout << "}" << endl;
    }
}
