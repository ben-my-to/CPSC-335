#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next, *back;
};

void insert(Node* & lst, int x) {
	Node* r = new Node; r->data = x; 
	r->next = nullptr; r->back = nullptr;
	if (lst == nullptr) lst = r;
	else {
		r->next = lst; lst->back = r;
		lst = r;
	}
}

void deleteDlist(Node* &d, int x) {
	if (d->data == x) { // delete the first node 
		Node* t = d;
		d = d->next;
		d->back = nullptr;
		delete t;
	}
	else {
		Node* t = d;
		Node* p = d;
		while(t != nullptr && t->data != x) {
			p = t;
			t = t->next;
		}
		if (t == nullptr)
			cout << x << " does not exist\n";
		else 
		if (t -> next == nullptr) { // delete the last node 
			p->next = nullptr;
			delete t;
		}
		else {
			p->next = t->next;
			t->next->back = p;
			delete t;
		}
	}
}

void displayList(Node* t) {
	while(t != nullptr) {
		cout << t->data << "->";
		t = t->next;
	}
	cout << "nullptr\n";
}

int main() {
	int a[5] = { 3, 8, 5, 7, 1 };
	Node* dList = nullptr;

	for (int i = 0; i < 5; ++i) insert(dList, a[i]);

	cout << "Doubly List: "; displayList(dList);

	cout << "Delete 1: "; deleteDlist(dList, 1); displayList(dList);

	cout << "Delete 5: "; deleteDlist(dList, 5); displayList(dList);

	cout << "Delete 3: "; deleteDlist(dList, 3); displayList(dList);

	return 0;
}

