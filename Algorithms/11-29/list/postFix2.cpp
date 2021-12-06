#include <iostream>
#include "stackpac_dll.h"
#include <string>

using namespace std;

int main() {
	int varA = 2, value, varC = 4, x, y, r;

	Stack<int, 10> p;
	p.clearStack();
	cout << "Enter a postfix expression: ";

	string id;
	while (cin >> id, id != "$") {
		// check whter the input is a number
		// if it is, then voert it to its numeric value
		if (isdigit(id[0])) {
			value = stoi(id);
			p.pushStack(value);
		}
		if (id == "varA")      p.pushStack(varA);
		else if (id == "varC") p.pushStack(varC);
		else if (id == "+") {
			x = p.popStack();
			y = p.popStack();
			r = y + x;
			p.pushStack(r);
		}
		else { // id == "*"
			x = p.popStack();
			y = p.popStack();
			r = y * x;
			p.pushStack(r);
		}
	}

	cout << "Value of the expression is: " << p.popStack() << endl;
	return 0;
}
