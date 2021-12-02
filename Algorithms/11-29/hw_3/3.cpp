#include "LinkedList.h"

using namespace std;
using T = int;

int main() {
	int i;
	LinkedList<T> setA, setB, setC;

	cout << "Enter the element of setA with -1 at the end: ";
	while (cin >> i && i != -1) setA.insertOrder(i);
	cout << "Enter the element of setB with -1 at the end: ";
	while (cin >> i && i != -1) setB.insertOrder(i);

	cout << "setA: "; setA.print(setA.head);
	cout << "setB: "; setB.print(setB.head);

	cout << "setA ∩ setB: ";
	setC.concatSet(setA.head, setB.head);
	setC.print(setC.head);
	return 0;
}