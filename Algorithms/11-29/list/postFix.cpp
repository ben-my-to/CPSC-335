#include <iostream>
#include "stackpac_dll.h"
#include <string>

using namespace std;

int main() {
	int a = 2, b = 3, c = 4, d = 5, x, y, r;
	Stack<int, 10> p;
	p.clearStack();
	cout << "Enter a postfix expression: ";

	char id;
	while (cin>>id, id!='$') {
		switch (id) {
			case 'a': p.pushStack(a); break;
			case 'b': p.pushStack(b); break;
			case 'c': p.pushStack(c); break;
			case 'd': p.pushStack(d); break;	
			case '+': {
				x = p.popStack();
				y = p.popStack();
				r = y + x; 
				p.pushStack(r);
				break;
			}
			case '*': {
				x = p.popStack();
				y = p.popStack();
				r = y * x;
				p.pushStack( r);
				break;
			}
		}
	}

	// pop the stack to see the result
	cout << "value of the expression is: " << p.popStack();
	cout << endl;
	return 0;
}
