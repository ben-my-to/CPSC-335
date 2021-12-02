#include <iostream>

using namespace std;

class BST {
private:
	struct node {
		int info;
		node *left, *right;
	} *root;

public:
	BST() { root = nullptr; }

	void displayBST(node *r) {
		// inorder traversal
		if (r != nullptr) {
			displayBST(r->left);
			cout << r->info << " ";
			displayBST(r->right);
		}
	}

	void insert(node* & r, int x) {
		// insert x in BST
		if (r == nullptr) {
			r = new node; r->info = x; r->left = r->right = nullptr;
		}
		else {
			if (x < r->info) insert(r->left, x);
			if (x > r->info) insert(r->right, x);
		}
	}

	void searchBST(node *r, int x) {
		if (r == nullptr) {
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

	int heightBT(node* r) {
		if (r == nullptr) return -1;
		else return 1 + max(heightBT(r->left), heightBT(r->right));
	}

	int countNodes(node* r) {
		if (r == nullptr) return 0;
		else return 1 + countNodes(r->left) + countNodes(r->right);
	}

	void insert(int x)    { insert(root, x);		 }
	void displayBST()     { displayBST(root);		 }
	void searchBST(int x) { searchBST(root, x);		 }
	int height()		  { return heightBT(root);	 }
  	int nodes()			  { return countNodes(root); }
};

int main() {
	BST t;
	#define SIZE 7
	int a[SIZE] = { 13, 11, 22, 8, 12, 15, 14 };
	//insert data from array a into BST
	for (int i = 0; i < SIZE; ++i) t.insert(a[i]);

	// display BST
	cout << "This is the content of tree: "; t.displayBST();
	cout << endl;
	/* search for item x = 12 */
	t.searchBST(12);

	cout << "Height of BST: " << t.height() << endl;
	cout << "Number of Nodes in BST: " << t.nodes() << endl;

	return 0;
}
