#include <iostream>

using namespace std;

struct Node {
	int info;
	Node *next, *back;
	
	Node() : info(0), next(nullptr), back(nullptr) {}
} *dlist;

class DList {
public:
	void insert(int x) { // insert x at the rear of doubly linked list
		Node *p, *temp;
		temp = new Node;
		temp->info = x;
		temp->next = nullptr;
		temp->back = nullptr;

		if (dlist == nullptr) dlist = temp;
		else {
			p = dlist;
			while (p->next != nullptr) p = p->next;
			p->next = temp;
			temp->back = p;
		}
	}

	void display() { // display doubly linked list from left-to-right
		Node *p = dlist;
		while (p != nullptr) {
			cout << p->info << "-->";
			p = p->next;
		}
		cout << "nullptr\n";
	}

	void delete_info(int x) { //  delete the Node with info = x
		// delete the node with info=x
		Node *p, *q;
		p = q = dlist;

		while (p->info != x) {
			q = p;
			p = p->next;
		}
		if (p == dlist) {
			// x is the first node 
			dlist = p->next;
			dlist->back = nullptr;
			delete p;
		}
		else {
			q->next = p->next;
			p->next->back = q;
			delete p;
		}
	}

	bool search(int x) { // search for x, if found return true, false otherwise
		Node *p = dlist;

		while (p != nullptr) {
			if (p->info == x) return true;
			p = p->next;
		}

		return false;
	}
};

int main() {
	DList d;
	int a[5] = { 4, 9, 1, 8, 3 };
	for (int i = 0; i < 5; i++) d.insert(a[i]);
	cout << "This is the content of the linked list\n\t";
	d.display();

	cout << "Delete 8, new linked list\n\t";
	d.delete_info(8);
	d.display();

	cout << "Delete the first node, new linked list\n\t";
	d.delete_info(4);
	d.display();

	int x = 8; // search for x = 8
	cout << x << (d.search(x) ? " is found" : " not found") << endl;	

	return 0;
}
