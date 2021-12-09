#include <iostream>
#include <string.h>
#include "stackpac_dll.h"

using namespace std;

void infix_to_post(char in[], int size) {
	Stack<char, 80> s;
	
	s.clearStack();
	int i = 0, k = 0;
	char ch;

	for (i = 0; i < size; ++i) {
		ch = in[i];
		if (isalpha(ch)) cout << ch;
		else {
			switch (ch) {
				case '*':
				case '/':
				case '+':
				case '(': {
					s.pushStack(ch);
					break;
				}
				case ')': {
					char c = s.popStack();
					while (c != '(') {
						cout << c;
						c = s.popStack();
					}
					break;
				}
			}
		}
	}
}

int main() {
	char infix[80];
	cout << "Enter an infix expression enclosed in(): ";
	cin >> infix;
	int size = strlen(infix);

	cout << "This is the postfix expression: ";
	infix_to_post(infix, size);
	cout << endl;

	return 0;
}
