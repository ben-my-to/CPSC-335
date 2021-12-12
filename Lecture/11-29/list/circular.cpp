#include <iostream>
using namespace std; 

struct Node {
	int info;
	Node *next;

	Node() : info(0), next(nullptr) {}
} *head;

class Circular {
public:
	void insert(int x) {
		Node *p = new Node; p->info = x;

		if (head == nullptr) {
			head = p;
			p->next = head;
		}
		else { // make temp to point to the lastNode 
			Node* temp = head;
			do {
				temp = temp->next;
			} while (temp->next != head);
			// insert x at the rear of the list
			temp->next = p;
			p->next = head;
		}
	}

	void display() {
		Node *p = head;
		if (p == nullptr) return;     
		do {
			cout << p->info << "-->";
			p = p->next;
		} while (p != head);
		cout << "nullptr\n";
	}
};

int main() {
	Circular c;
	int a[5] = { 8, 3, 9, 6, 1 };
	for (int i = 0; i < 5; i++) c.insert(a[i]);
	c.display();

	return 0;
}
