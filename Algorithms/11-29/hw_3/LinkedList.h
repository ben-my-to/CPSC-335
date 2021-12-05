#pragma once

#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;

	Node() : data(0), next(nullptr) {}
	Node(const T& d) : data(d), next(nullptr) {}
};

template <typename T>
class LinkedList {
public:
	Node<T> *head, *tail;
	size_t size;

	LinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~LinkedList() { removeList(head); }
	

	void insertBack(const T& value) {
		Node<T>* temp = new Node<T>(value);
		if (!head) head = temp;
		else {
			Node<T>* curr = head;
			while (curr->next != nullptr) curr = curr->next;	
			curr->next = temp;
			tail = temp;
		}
		size++;
	}

	void insertAfter(const T& value) {
		Node<T>* temp = new Node<T>(value);
		if (!head) head = temp;
		else {
			Node<T>* curr = head;
			head = temp;
			temp->next = curr;
		}
		size++;
	}

	void insertOrder(const T& value) {
		Node<T>* r = new Node<T>(value);
		Node<T> *p = head, *q = head;

		if (head == nullptr) head = r;
		else {
			while (p && value > p->data) {
				q = p;
				p = p->next;
			}
			if (p == q) { // insert in front
				r->next = p;
				head = r;
			} else { // insert at the rear
				r->next = p;
				q->next = r;
			}
		}
		size++;
	}

	size_t getsize() const { return size; }

	void concatSet(Node<T>* a, Node<T>* b) {
		#define A_SMALLER a && b && a->data < b->data
		#define B_SMALLER a && b && b->data < a->data
		#define EQUAL a && b && a->data == b->data 
		while (a && b) {
			if (A_SMALLER) {
				while (A_SMALLER) a = a->next;
			}
			else if (B_SMALLER) {
				while (B_SMALLER) b = b->next;
			}
			if (EQUAL) {
				insertOrder(a->data);
				a = a->next;
				b = b->next;
			}
		}
	}

	void removeList(Node<T>* curr) {
		if (!curr) return;
		else removeList(curr->next);
		delete curr;
	}

	void print(Node<T>* curr) const {
		while (curr) {
			std::cout << curr->data << "->";
			curr = curr->next;
		}
		std::cout << "nullptr\n";
	}
};
