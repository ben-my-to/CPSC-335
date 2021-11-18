#include <iostream>

using namespace std;

class BST {
private:
	struct node {
		int info;
		node *left, *right;
	} *root;

public:
	BST() { root = NULL; }

	void displayBST(node *r) {
		// inorder traversal
		if (r != NULL) {
			displayBST(r->left);
			cout << r->info << " ";
			displayBST(r->right);
		}
	}

	void insert(node* & r, int x) {
		// insert x in BST
		if (r == NULL) {
			r = new node; r->info = x; r->left = r->right = NULL;
		}
		else {
			if (x < r->info) insert(r->left, x);
			if (x > r->info) insert(r->right, x);
		}
	}

	void searchBST(node *r, int x) {
		if (r == NULL) {
			cout << x << " does not exist\n"; return;
		}
		else if (r->info == x) {
			cout << x << " is found\n"; return;
		}
		else {
			if (x < r->info) { searchBST(r->left, x);  } //search left-sub-tree
			if (x > r->info) { searchBST(r->right, x); } //search right-sub-tree
		}
	}

	void insert(int x)    { insert(root, x);    }
	void displayBST()     { displayBST(root);   }
	void searchBST(int x) { searchBST(root, x); }
};

int main() {
		BST t;
		int a[6] = { 13, 11, 22, 8, 12, 15 };
		//insert data from array a into BST
		for (int i = 0; i < 6; ++i) t.insert(a[i]);

		// display BST
		cout << "This is the content of tree: "; t.displayBST();
		cout << endl;
		/* search for item x = 12 */
		t.searchBST(12);

		return 0;
}