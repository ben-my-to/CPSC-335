#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>

template <typename T>
struct Node {
	T data;
	Node<T> *left, *right;

	Node() : data(""), left(nullptr), right(nullptr) {}
	Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
	Node<T>* root;

public:
	BST() : root(nullptr) {}

	void insert(Node<T>* &curr, const T& v) {
		if (!curr) curr = new Node<T>(v);
		else {
			if (v < curr->data) insert(curr->left, v);
			if (v > curr->data) insert(curr->right, v);
		}
	}

	void inOrder(Node<T>* curr) {
		if (curr) {
			inOrder(curr->left);
			std::cout << curr->data << " ";
			inOrder(curr->right);
		}
	}

	Node<T>* find(Node<T>* curr, const T& v) {
		if (curr) {
			if (curr->data == v) return curr;
			if (v < curr->data) return find(curr->left, v); // search left-sub-tree
			if (v > curr->data) return find(curr->right, v); // search right-sub-tree
		}
		return nullptr;
	}

	int heightBT(Node<T>* r) {
		if (r == nullptr) return -1;
		else return 1 + std::max(heightBT(r->left), heightBT(r->right));
	}

	bool findAncestors(Node<T>* curr, const T& target) {
		if (!curr) return false;
		if (curr->data == target) return true;

		if (findAncestors(curr->left, target) || findAncestors(curr->right, target)) {
			std::cout << curr->data << " ";
			return true;
		}
		return false;
	}

	Node<T>* removeLeaves(struct Node<T>* curr) {
		if (!curr) return nullptr;
		if (!curr->left && !curr->right) {
			std::cout << curr->data << " ";
			free(curr);
			return nullptr;
		}

		curr->left = removeLeaves(curr->left);
		curr->right = removeLeaves(curr->right);

		return curr;
	}

	void rotate(Node<T>* curr, int s) {
		if (curr) {
			rotate(curr->right, s += 5);
			std::cout << std::setw(s) << curr->data << std::endl;
			rotate(curr->left, s);
		}		
	}

	int countNodes(Node<T>* curr) {
		return (curr ? 1 + countNodes(curr->left) + countNodes(curr->right) : 0); 
	}

	void insert(const T& x)		    { insert(root, x);		   }
	void inOrder()                  { inOrder(root);		   }
	int height()		            { return heightBT(root);   }
  	int nodes()			            { return countNodes(root); }
	void removeLeaves()             { removeLeaves(root);	   }
	void rotate()				    { rotate(root, 0);		   }
	void findAncestors(const T& x)  { findAncestors(root, x);  }
	Node<T>* find(const T& x)	    { find(root, x);		   }

	void findDescendants(const T& x) {
		Node<T>* curr = find(root, x);
		if (!curr) std::cout << "could not find element \'" << x << "\'";
		else if (!curr->left && !curr->right) std::cout << "\'" << x << "\' is a leaf";
		else {
			inOrder(curr->left);
			inOrder(curr->right);
		}
	}
};
