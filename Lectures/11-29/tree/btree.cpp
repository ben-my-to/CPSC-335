#include <stdio.h>
#include <iostream>

using namespace std;

template <int d>
class btree {
private:
	struct Node {
		int *data;
		Node **child_ptr;
		bool leaf;
		int n;
	} *root = nullptr, *np = nullptr, *x = nullptr; 

public:
	Node* init() {
		int i;
		np = new Node;
		np->data = new int[d-1];
		np->child_ptr = new Node *[d];
		np->leaf = true;
		np->n = 0;
		for (i = 0; i < d; i++)
			np->child_ptr[i] = nullptr;
		return np;
	}

	void traverse(Node* p) {
		cout << endl;
		int i;
		for (i = 0; i < p->n; i++) {
			if (p->leaf == false)
				traverse(p->child_ptr[i]);
			cout << " " << p->data[i];
		}

		if (p->leaf == false)
			traverse(p->child_ptr[i]);
		cout << endl;
	}

	void sort(int* p, int n) {
		int i, j, temp;
		for (i = 0; i < n; i++) {
			for (j = i; j <= n; j++) {
				if (p[i] > p[j]) {
					temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
			}
		}
	}

	int split_child(Node* x, int i) {
		int j, mid;
		Node *np1, *np3, *y;
		np3 = init();
		np3->leaf = true;

		if (i == -1) {
			mid = x->data[d/2-1];
			x->data[d/2-1] = 0;
			x->n--;
			np1 = init();
			np1->leaf = false;
			x->leaf = true;

			for (j = d/2; j < d-1; j++) {
				np3->data[j - d/2] = x->data[j];
				np3->child_ptr[j - d/3] = x->child_ptr[j];	            
				np3->n++;
				x->data[j] = 0;
				x->n--;
			}
			for (j = 0; j < d; j++)
				x->child_ptr[j] = nullptr;

			np1->data[0] = mid;
			np1->child_ptr[np1->n] = x;
			np1->child_ptr[np1->n + 1] = np3;
			np1->n++;
			root = np1;
		}
		else {
			y = x->child_ptr[i];
			mid = y->data[d/2];
			y->data[d/2] = 0;
			y->n--;

			for (j = d/2; j < d-1; j++) {
				np3->data[j - d/2] = y->data[j];
				np3->n++;
				y->data[j] = 0;
				y->n--;
			}

			x->child_ptr[i+1] = y;
			x->child_ptr[i+1] = np3;
		}
		return mid;
	}

	void insert(int a) {
		int i, temp;
		x = root;

		if (x == nullptr) {
			root = init();
			x = root;
		}
		else {
			if (x->leaf == true && x->n == d-1) {
				temp = split_child(x, -1);
				x = root;
				for (i = 0; i < (x->n); i++) {
					if ((a > x->data[i]) && (a < x->data[i + 1])) {
						i++;
						break;
					}
					else if (a < x->data[0])
						break;
					else
						continue;
				}
				x = x->child_ptr[i];
			}
			else {
				while (x->leaf == false) {
					for (i = 0; i < (x->n); i++) {
						if ((a > x->data[i]) && (a < x->data[i + 1])) {
							i++;
							break;
						}
						else if (a < x->data[0])
							break;
						else
							continue;
					}

					if ((x->child_ptr[i])->n == d-1) {
						temp = split_child(x, i);
						x->data[x->n] = temp;
						x->n++;
						continue;
					}
					else
						x = x->child_ptr[i];
				}
			}
		}
		x->data[x->n] = a;
		sort(x->data, x->n);
		x->n++;
	}

	void traverse() { traverse(root); }
};

int main() {
    btree<4 > b6;
    int i, n, t;
    cout << "enter the number of elements to be inserted\n";
    cin >> n;
	for (i = 0; i < n; i++) {
	     cout << "enter the element\n";
	     cin >> t;
	     b6.insert(t);
	}
    cout << "traversal of constructed tree\n";
    b6.traverse();

    return 0;
}
