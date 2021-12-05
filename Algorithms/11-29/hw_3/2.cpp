#include <pthread.h>
#include "DoublyLinkedList.h"
#include <stack>
#include <cctype>

using namespace std;
using T = char;

DoublyLinkedList<T> list;
 stack<T> f, s;

void* forward(void* arg) {
	Node<T>* curr = static_cast<Node<T>*>(arg);
	while (curr) {
		char in = tolower(curr->data);
		switch (in) {
			case '.':
			case ',':
			case ';':
			case ' ': break;
			default: f.push(in);
		}
		curr = curr->next;
	}
	pthread_exit(0);
}

void* backward(void* arg) {
	Node<T>* curr = static_cast<Node<T>*>(arg);
	while (curr) {
		char in = tolower(curr->data);
		switch (in) {
			case '.':
			case ',':
			case ';':
			case ' ': break;
			default: s.push(in);
		}
		curr = curr->prev;
	}
	pthread_exit(0);
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "usage: ./<file-name> <string>\n";
		return -1;
	}

	string phrase = argv[1];
	for (T c : phrase) list.insert(c);

	pthread_t p1, p2;
	pthread_create(&p1, NULL, forward, list.head);
    pthread_create(&p2, NULL, backward, list.tail);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	while (!s.empty() && f.top() == s.top()) {
		s.pop();
		f.pop();
	}

	cout << "The phrase is " << (s.empty() ? "a palindrome" : "not a palidrome") << endl;

	return 0;
}
