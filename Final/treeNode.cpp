#include <iostream>

using namespace std;

/**************************/

struct treeNode {
	int info;
	treeNode *left, *right;

	treeNode() : info(0), left(nullptr), right(nullptr) {}
	treeNode(const int& i) : info(i), left(nullptr), right(nullptr) {}
};

void insert(treeNode* &curr, const int& v) {
	if (!curr) curr = new treeNode(v);
	else {
		if (v < curr->info) insert(curr->left, v);
		if (v > curr->info) insert(curr->right, v);
	}
}

int countNodes(treeNode *curr) {
	if (!curr) return 0;
	else return 1 + countNodes(curr->left) + countNodes(curr->right); 
}

/**************************/

struct listNode {
	int info;
	listNode *next;

	listNode() : info(0), next(nullptr) {}
	listNode(const int& i) : info(i), next(nullptr) {}
};

listNode *list;

void insertList(const int& v) {
	listNode* temp = new listNode(v);
	if (!list) list = temp;
	else {
		listNode* curr = list;
		while (curr->next != nullptr) curr = curr->next;	
		curr->next = temp;
	}
}

void displayReverse(listNode *p) {
	if (p == NULL) return;
	if (p != NULL) displayReverse(p->next);
	cout << p->info << "->";
}

int main() {
	treeNode *root;
	listNode *stack, *queue, *ordered;

	insert(root, 4);
	insert(root, 5);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 8);
	insert(root, 7);
	cout << "Number of Nodes in Binary Tree: " << countNodes(root) << endl;

	/* Problem 7b */
	insertList(1);
	insertList(2);
	insertList(3);
	insertList(4);
	insertList(5);
	insertList(6);
	insertList(7);
	cout << "Reversing List: "; displayReverse(list); cout << endl;

	return 0;
}
