#include "BST.h"
#include <string>

#define SIZE 12

using namespace std;

int main() {
	BST<string> t;
	string monthName[SIZE] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	for (int i = 0; i < SIZE; ++i) t.insert(monthName[i]);

	cout << "InOrder Traversal: "; t.inOrder();
	cout << "\nHeight: " << t.height();
	cout << "\nAncestors of 'Dec': "; t.findAncestors("Dec");
	cout << "\nDescendants of 'May': "; t.findDescendants("May");
// swap lines 19 and 20
	cout << "\nRotating BST: "; cout << endl; t.rotate();
	cout << "\nRemoving Leaves: "; t.removeLeaves();
	cout << "\nNumber of Nodes: " << t.nodes() << endl;

	return 0;
}
