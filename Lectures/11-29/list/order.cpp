#include <iostream>

using namespace std;

struct Node {
	int info;
	Node *next;
};

void displayList(Node* p) { // display linked list
	Node* t = p;
	while (t != nullptr) {
		cout << t->info << "->";
		t = t->next;
	}
	cout << "nullptr\n";
}

void stackList(Node* & s, int x) { // create a stack, insert x in front of list
	// insert x in front of list
	Node* r = new Node;
	r->info = x; r->next = nullptr;
	if (s == nullptr)
		s = r;
	else
		r->next = s; s = r;
}

void queueList(Node* & q, int x) { // create a queue, insert x at the rear of list
	// insert x at the rear of the list
	Node* r = new Node;
	r->info = x;
	r->next = nullptr;

	if (q == nullptr) q = r;
	else {
		// make p to point at the rearNode 
		Node* p = q;
		while (p->next != nullptr) p = p->next;
		p->next = r;
	}
}
void orderList(Node* & ord , int x) { // create an ordered list
	// insert x in the list and keep the list sorted
	Node* r = new Node;
	r->info = x;
	r->next = nullptr;
	// find the insertion place;
	Node* p = ord, *q = ord;

	if (ord == nullptr) ord = r;
	else {
		while (p!= nullptr && x > p->info) {
			q = p;
			p = p->next;
		}
		if (p == q) {
			// insert in front
			r->next = p;
			ord = r;
		} else {
			// insert at the rear
			r->next = p;
			q->next = r;
		}
		
	}
}

int countNodes(Node* p) { // return the number of Nodes in linked list recursively
	return (p != nullptr) ? 1 + countNodes(p->next) : 0;
}

void displayReverse(Node* p) { // display linked list in reverse order
	// display list in reverse order
	if (p == nullptr) return;
	if (p != nullptr) displayReverse(p->next);
	cout << p->info << "  ";
	/*
		this statement is after recursive call, each time the 
		function calls itself, the execution of the statement 
		will be remembered by the compiler by pushing the      
		statement in stack
	*/
}

void unionSet(Node* b, Node* c, Node* & u) { // return the union of two ordered list
	while (b != nullptr && c != nullptr) {
		if (b->info < c->info) {
			orderList(u, b->info);
			b = b->next;
		}
		else if (c->info < b->info) {
			orderList(u, c->info);
			c = c->next;
		}
		else {
			orderList(u, b->info);
			b = b->next;
			c = c->next;
		}
	}

	while (b != nullptr) {
		orderList(u, b->info);
		b = b->next;
	}

	while (c != nullptr) {
		orderList(u, c->info); c = c->next;
	}
}

string EvenOdd(Node* r) { // determine whether the number of Nodes are ODD or EVEN
	while (r != nullptr && r->next != nullptr) r = r->next->next;
	return (r == nullptr) ? " Even\n" : " Odd\n";
}

Node* findMiddleNode(Node* r) { // return a pointer to the middle Node of LL
	Node *t1, *t2;
	t1 = t2 = r;

	while (t1->next != nullptr) {
		t1 = t1->next->next;
		if (t1 == nullptr) break;
		t2 = t2->next;
	}

	return t2;
} 

int main() {
	Node *stack = nullptr, *queue = nullptr, *order = nullptr;
	int a[7] = { 10, 8, 6, 9, 2, 4, 1 };
	
	// insert a in stack
	for (int i = 0; i < 7; ++i) stackList(stack, a[i]);
	cout << "Stack content: ";
	displayList(stack);  

	// insert array a in queue
	for (int i = 0; i < 7; i++) queueList(queue, a[i]);
	cout << "Queue content: ";
	displayList(queue);

	// insert array in an ordered list
	for (int i = 0; i < 7; ++i) orderList(order, a[i]);
	cout << "Order content: ";
	displayList(order);

	// display number of Nodes in stack/queue/order
	cout << "Number of Nodes = " << countNodes(stack) << endl;

	// display ordered list in reverse(from highest to lowest)
	cout << "Order list in reverse order: ";
	displayReverse(order);
	cout << endl;


	int b[4] = { 1, 8, 3, 9 }; // Let setB =
	int c[6] = { 1, 2, 3, 4, 5, 6 }; // Let setC =

	// find setU = (setA U setB)
	Node *setB = nullptr, *setC = nullptr, *setU = nullptr;

	for (int i = 0; i < 4; ++i) orderList(setB, b[i]);
	for (int i = 0; i < 6; ++i) orderList(setC, c[i]);

	unionSet(setB, setC, setU); //setU= setB union setC

	displayList(setB);
	displayList(setC);
	displayList(setU);

    // find the middle Node of setB and setC
	Node *mb = findMiddleNode(setB);
	if (EvenOdd(setB) == "EVEN")
		cout << "setB is EVEN and middles are " << mb->info << " and " << mb->next->info << endl;
	else
		cout << "setB is ODD and middle is " << mb->info << endl;

	Node*mc = findMiddleNode(setC);
	if (EvenOdd(setC) == "EVEN")
		cout << "setC is EVEN and middles are " << mc->info << " and " << mc->next->info << endl;
	else
		cout << "setC is ODD and middle is " << mc->info << endl;

	return 0;
}
