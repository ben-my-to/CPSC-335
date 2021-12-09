#include "LinkedList.h"

using namespace std;
using T = int;

int main() {
	int i;
	LinkedList<T> setA, setB, setC;

	cout << "Enter the element of setA with -1 at the end: ";
	while (cin >> i && i != -1 && setA.size <= 10) setA.insertOrder(i);
	cout << "Enter the element of setB with -1 at the end: ";
	while (cin >> i && i != -1 && setB.size <= 10) setB.insertOrder(i);
	setC.concatSet(setA.head, setB.head);

	cout << "setA: " << setA;
	cout << "setB: " << setB;
	cout << "setA ∩ setB: " << setC;
	return 0;
}
