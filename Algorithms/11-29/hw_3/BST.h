#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>

template <typename T>
struct Node {
	T data;
	Node<T> *left, *right;

	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
	Node<T>* root = nullptr;

public:
	void insert(Node<T>* &curr, T x) {
		if (!curr) curr = new Node<T>(x);
		else {
			if (x < curr->data) insert(curr->left, x);
			if (x > curr->data) insert(curr->right, x);
		}
	}

	void inOrder(Node<T>* curr) {
		if (curr) {
			inOrder(curr->left);
			std::cout << curr->data << " ";
			inOrder(curr->right);
		}
	}

	Node<T>* find(Node<T>* curr, T x) {
		if (curr) {
			if (curr->data == x) return curr;
			if (x < curr->data) { return find(curr->left, x);  } // search left-sub-tree
			if (x > curr->data) { return find(curr->right, x); } // search right-sub-tree
		}
		return NULL;
	}

	int heightBT(Node<T>* r) {
		if (r == nullptr) return -1;
		else return 1 + std::max(heightBT(r->left), heightBT(r->right));
	}

	bool findAncestors(Node<T>* curr, T target) {
		if (!curr) return false;
		if (curr->data == target) return true;

		if (findAncestors(curr->left, target) || findAncestors(curr->right, target)) {
			std::cout << curr->data << " ";
			return true;
		}
		return false;
	}

	void removeLeaves(Node<T>* &curr) {
		if (curr) {
			removeLeaves(curr->left);
			if (!curr->left && !curr->right) {
				std::cout << curr->data << " ";
				free(curr);
			}
			removeLeaves(curr->right);
		}
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

	void insert(T x)        { insert(root, x);		   }
	void inOrder()		    { inOrder(root);		   }
	int height()		    { return heightBT(root);   }
  	int nodes()			    { return countNodes(root); }
	void removeLeaves()     { removeLeaves(root);	   }
	void rotate()           { rotate(root, 0);		   }
	void findAncestors(T x) { findAncestors(root, x);  }
	Node<T>* find(T x)	    { find(root, x);		   }

	void findDescendants(T x) {
		Node<T>* curr = find(root, x);
		inOrder(curr->left);
		inOrder(curr->right);
	}
};
