#include <iostream>

using namespace std;

struct Node {
	char data;
	Node *left, *right;
};

char postFix[50];
int top = -1;
Node* stack[4];

int r(char inputch) {
	if (inputch == '+' || inputch == '-' || inputch == '*' || inputch == '/')
		return (-1);
	else if (isalpha(inputch))
		return (1);
	else
		return (-10);
}

void pushStack(Node* tree) {
	top++;
	stack[top] = tree;
}

Node* popStack() {
	top--;
	return (stack[top + 1]);
}

void construct_expression_tree(char* expression) {
	char s;
	Node *newl, *T1, *T2;
	int flag;
	s = expression[0];
	for (int i = 1; s != '\0'; i++) {
		flag = r(s);
		if (flag == 1) {
			newl = new Node;
			newl->data = s;
			newl->left = nullptr;
			newl->right = nullptr;
			pushStack(newl);
		}
		else {
			T1 = popStack();
			T2 = popStack();
			newl = new Node;
			newl->data = s;
			newl->left = T2;
			newl->right = T1;
			pushStack(newl);
		}
		s = expression[i];
	}
}

void preOrder(Node* tree) { // display the expression tree using pre-order traversal
	if (tree != nullptr) {
		cout << tree->data;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(Node* tree) { // display the expression tree using in-order traversal
	if (tree != nullptr) {
		inOrder(tree->left);
		cout << tree->data;
		inOrder(tree->right);
	}
}

void postOrder(Node *tree) { // display expression tree using post-order traversal
	if (tree) {
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->data;
	}
}

int main() {
	cout << "Enter Postfix Expression : "; cin >> postFix;
	construct_expression_tree(postFix);

	cout << "\nIn-Order Traversal : "; inOrder(stack[0]);
	cout << "\nPre-Order Traversal : "; preOrder(stack[0]);
	cout << "\nPost-Order Traversal : "; postOrder(stack[0]); cout << endl;
	return 0;
}
